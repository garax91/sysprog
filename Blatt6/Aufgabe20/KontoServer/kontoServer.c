#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int *konto;
 	konto = 0;

	int mainSocket = socket(AF_INET,SOCK_STREAM,0);	
	int err;
	int port;
	struct sockaddr_in addrSock;


	if(mainSocket < 0)
	{
		printf("ERROR bei socket(..)"); 
		return EXIT_FAILURE;
	}

	if(argc <= 1)
	{
		printf("ERROR, keine gültige portnummer eingegeben!");
		return EXIT_FAILURE;
	}
	const char* portInserted = argv[1];
	port = atoi(portInserted);
	if(port == 0)
	{
		printf("ERROR, keine gültige portnummer eingegeben!");
		return EXIT_FAILURE;
	}

	
	printf("Port : %d\n", port);
	

	addrSock.sin_family = AF_INET;
printf("a\n");
	addrSock.sin_port = htons(port);
printf("b\n");
	addrSock.sin_addr.s_addr = htonl(INADDR_ANY);

	printf("starting bind");

	err = bind(mainSocket, (struct sockaddr *) &addrSock, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("ERROR bei bind(..)");
	}

	printf("SUCCESSful Server bind");

	err = listen(mainSocket, 5);
	if(err < 0)
	{
		printf("ERROR bei listen(..)");
	}

	printf("SUCCESSful Server ready");

	while(1)
	{
		struct sockaddr_in addrClient;
		socklen_t addrlen;

		addrlen =  sizeof(struct sockaddr_in);
		int currentSocket = accept(mainSocket, (struct sockaddr*) &addrClient, &addrlen);
		if(currentSocket < 0)
		{
			printf("ERROR in accept(..)");
		}

		printf("SUCCESSful accepted");

		while(1)
		{
			size_t writeSize = sizeof(konto);
			ssize_t errSizeWrite = write(currentSocket, konto, writeSize);
			if(errSizeWrite < 0)
			{
				printf("ERROR in write(..)");
			}

			char strRead[19];
			size_t readSize = sizeof(strRead);
			ssize_t errSizeRead = read(currentSocket, strRead, readSize);
			if(errSizeRead < 0)
			{
				printf("ERROR in read(..)");
			}
			if(err == 0)
			{
				printf("Client bricht Verbindung ab");
				break;
			}

			printf("EMPFANGEN: %s\n", strRead);

		//	konto = *konto + *kontoChange;
		//	konto += kontoChange;
		}
		
		err = close(currentSocket);
		if(err < 0)
		{
			printf("ERROR, currentSocket kann nicht geschlossen werden");
		}
	}

	err = close(mainSocket);
	if(err < 0)
	{
		printf("ERROR, mainSocket kann nicht geschlossen werden");
	}


}
