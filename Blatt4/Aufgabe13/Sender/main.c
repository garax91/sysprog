#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd, err;
	struct sockaddr_in addrDest;
	char msg[64], ipAdress[16];
	int port;

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		printf("Fehler bei der Socketerstellung!\n");
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
		printf("____________________________________________________________\n");
		printf(">>Nachricht: \n>>");
		scanf("%*c%63[^\n]", msg);
		if(strcmp(msg, "exit") == 0)
		{
			break;
		}
	
		err = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*) &addrDest, sizeof(struct sockaddr_in));
		if(err < 0)
		{
			printf("senden fehlgeschlagen\n");
			return EXIT_FAILURE;
		}


		printf("nachricht gesendet!\n");
	}

	return EXIT_SUCCESS;
}
