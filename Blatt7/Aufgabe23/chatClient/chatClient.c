#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "unp_readline.h"

int main(int argc, char *argv[])
{
	int mainSocket = socket(AF_INET,SOCK_STREAM,0);	
	int err;
	int port;
	char ipAdress[16], nick[19], ownIp[16], strSend[9999], msg[9999];
	struct sockaddr_in addrSock, ownAddr;
	fd_set rset;


	if(mainSocket < 0)
	{
		printf("ERROR bei socket(..)"); 
		return EXIT_FAILURE;
	}


	printf(">>Gebe den Host an: \n>>");
	scanf("%s", ipAdress);
	printf(">>Gebe den Port an: \n>>");
	scanf("%d", &port);

	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(port);
	addrSock.sin_addr.s_addr = inet_addr(ipAdress);

	err = connect(mainSocket, (struct sockaddr *) &addrSock, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("ERROR, bei connect(..)\n");
		return EXIT_FAILURE;
	}
	
/*	size_t size_t_length = sizeof(struct sockaddr_in);
	err = getsockname(mainSocket, (struct sockaddr *) &ownAddr, size_t_length);
	ownIp = ntohs(ownAddr.sin_port);
*/
	printf("SUCCESSful connected\n");

	printf(">>Gebe Nick ein: \n>>");
	scanf("%s", nick);

	printf(">>Schreibe Nachrichten: \n>>");

	while(1)
	{
		FD_ZERO(&rset);
		FD_SET(mainSocket, &rset);
		FD_SET(STDIN_FILENO, &rset);

		int highest_fd = mainSocket;
		if(STDIN_FILENO > highest_fd)
		{
			highest_fd = STDIN_FILENO;
		}

		err = select(highest_fd + 1, &rset, NULL, NULL, NULL);
		if(err < 0)
		{
			printf("ERROR bei seelct(..)\n");
		}
		if(FD_ISSET(mainSocket, &rset))
		{
			char readBuffer[99999];
			size_t readSize = sizeof(readBuffer);
			ssize_t errSizeRead = read(mainSocket, readBuffer, readSize);
			if(errSizeRead<0)
			{
				printf("empfangen fehlgeschlagen\n");
				return EXIT_FAILURE;
			}
			if(errSizeRead==0)
			{
				printf("Server hat Verbindung getrennt\n");
				return EXIT_FAILURE;
			}
			printf(">>%s", readBuffer);
		}
		if(FD_ISSET(STDIN_FILENO, &rset))
		{
			ssize_t msgSize = readline(STDIN_FILENO, msg, 2048);
			if(msgSize < 0)
			{
				printf("ERROR with readline(..)");
			}
			//sprintf(strSend, "%s%s%s", nick, ownIp, msg);
			sprintf(strSend, "%s : %s", nick, msg);
			size_t sendSize = sizeof(strSend);
			ssize_t errSizeWrite = write(mainSocket, strSend, sendSize);
			if(errSizeWrite < 0)
			{
				printf("senden fehlgeschlagen\n");
				return EXIT_FAILURE;
			}
			if(strcmp(msg, "exit\n") == 0)
			{
				break;
			}
		}

		printf("____________________________________________________________\n");
	}


	err = close(mainSocket);
	if(err < 0)
	{
		printf("ERROR, mainSocket kann nicht geschlossen werden");
	}

	return EXIT_SUCCESS;

}
