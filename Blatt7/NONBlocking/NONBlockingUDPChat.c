#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unp_readline.h"

int initSock()
{
	int fd, err;
	struct sockaddr_in addr;
	socklen_t flen;

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		printf("Fehler bei der Socketerstellung!\n");
		return -1;
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	err = bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("Fehler beim bind\n");
		return -1;
	}
	flen = sizeof(addr);
	err = getsockname(fd, (struct sockaddr *) &addr, &flen);
	if(err < 0)
	{
		printf("Fehler bei getsocketname(..)\n");
		return -1;
	}
	printf("Server erfolgreich initialisiert! Bitte nutze folgene Daten, um mit dem Server zu kommunizieren:\n");
	printf("==============================\n");
	printf("Port : %d\n", ntohs(addr.sin_port));
	printf("==============================\n\n\n");

	return fd;
}

int main()
{
	struct sockaddr_in from, addrDest;
	socklen_t flen2 = sizeof(from);	
	char msg[64], ipAdress[16];
	int fd, port, len, err, res;
	fd_set rset;
	
	fd = initSock();
	if(fd < 0)
	{
		printf("ERROR initSock()");
		return EXIT_FAILURE;
	}
	printf(">>Gebe den Host an: \n>>");
	scanf("%s", ipAdress);
	printf(">>Gebe den Port an: \n>>");
	scanf("%d", &port);

	addrDest.sin_family = AF_INET;
	addrDest.sin_port = htons(port);
	addrDest.sin_addr.s_addr = inet_addr(ipAdress);


	printf("============================================\n");
	printf("Schreibe 'exit' um das Programm zu beenden!!\n");
	printf("============================================\n\n");

	while(1)
	{
		FD_ZERO(&rset);
		FD_SET(fd, &rset);
		FD_SET(STDIN_FILENO, &rset);

		int highest_fd = fd;
		if(STDIN_FILENO > highest_fd)
		{
			highest_fd = STDIN_FILENO;
		}
		
		
		printf(">>Schreibe Nachricht: \n>>");

		res = select(highest_fd + 1, &rset, NULL, NULL, NULL);
		if(res < 0)
		{
			printf("ERROR bei seelct(..)\n");
		}
		if(FD_ISSET(fd, &rset))
		{
			len = recvfrom(fd, msg, sizeof(msg), 0, (struct sockaddr *) &from, &flen2);
			if(len<0)
			{
				printf("empfangen fehlgeschlagen\n");
				return EXIT_FAILURE;
			}
			printf(">>Nachricht von %s durch den Port %d erhalten:\n>>Nachricht: %s\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port), msg);

			if(strcmp(msg, "exit\n") == 0)
			{
				printf("Ihr Gesprächspartner hat den Chat verlassen!\n");
				break;
			}
		}
		if(FD_ISSET(STDIN_FILENO, &rset))
		{
			size_t readSize = readline(STDIN_FILENO, msg, 2024);
			if(readSize < 0)
			{
				printf("ERROR with readline(..)");
			}

			err = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*) &addrDest, sizeof(struct sockaddr_in));
			if(err < 0)
			{
				printf("senden fehlgeschlagen\n");
				return EXIT_FAILURE;
			}
			else
			{
				printf(">>Nachricht von mir gesendet:\n>>Nachricht: %s\n", msg);
			}

			if(strcmp(msg, "exit\n") == 0)
			{
				break;
			}
		}

		printf("____________________________________________________________\n");
	}
	
	printf("Programm wird beendet . . . . .\n");

	return EXIT_SUCCESS;
}
