#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd, err, len;
	struct sockaddr_in addr, from;
	socklen_t flen1, flen2;
	char msg[64];
	
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		printf("Fehler bei der Socketerstellung!\n");
		return EXIT_FAILURE;
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	err = bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("Fehler beim bind\n");
		return EXIT_FAILURE;
	}
	flen1 = sizeof(addr);
	err = getsockname(fd, (struct sockaddr *) &addr, &flen1);
	if(err < 0)
	{
		printf("Fehler bei getsocketname(..)\n");
		return EXIT_FAILURE;
	}
	printf("Server erfolgreich initialisiert! Bitte nutze folgene Daten, um mit dem Server zu kommunizieren:\n");
	printf("==============================\n");
	printf("Port : %d\n", ntohs(addr.sin_port));
	printf("==============================\n\n\n");


	flen2 = sizeof(from);	

	while(1)
	{
		len = recvfrom(fd, msg, sizeof(msg), 0, (struct sockaddr *) &from, &flen2);
		if(len<0)
		{
			printf("empfangen fehlgeschlagen\n");
			return EXIT_FAILURE;
		}
		printf(">>Nachricht von %s durch den Port %d erhalten!\n>>Nachricht: %s\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port), msg);
		printf("____________________________________________________________\n");
	}
	return EXIT_SUCCESS;
}
