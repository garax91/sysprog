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
	int mainSocket = socket(AF_INET,SOCK_STREAM,0);	
	int err;
	int port;
	char ipAdress[16];
	struct sockaddr_in addrSock;


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

	printf("SUCCESSful connected\n");

	int opt = -1;
	int betrag = 0;
	char strSend[19];
	char strOption;
	char readBuffer[9999];	
	int kontoNummer;

	size_t readSize = sizeof(readBuffer);
	ssize_t errSizeRead = read(mainSocket, readBuffer, readSize);
	if(errSizeRead < 0)
	{
		printf("ERROR, in read(..)");
	}
	if(errSizeRead == 0)
	{
		printf("Server hat Verbindung getrennt . . \n");
		return EXIT_FAILURE;
	}

	printf("%s\n", readBuffer);
	scanf("%d", &kontoNummer);

	if(kontoNummer < 17 && kontoNummer >= 0)
	{
		sprintf(strSend, "#%d", kontoNummer);

		size_t sendSize = sizeof(strSend);
		ssize_t errSizeWrite = write(mainSocket, strSend, sendSize);
		if(errSizeWrite < 0)
		{
			printf("ERROR, in write(..)");
		}

		size_t readSize = sizeof(readBuffer);
		ssize_t errSizeRead = read(mainSocket, readBuffer, readSize);
		if(errSizeRead < 0)
		{
			printf("ERROR, in read(..)");
		}
		if(errSizeRead == 0)
		{
			printf("Server hat Verbindung getrennt . . \n");
			return EXIT_FAILURE;
		}
		
		printf("%s\n", readBuffer);
		if(readBuffer[0] != '+')
		{
			return EXIT_FAILURE;
		}
	}
	else
	{
		printf("Ungültige Kontonummer eingegeben!\n");
		return EXIT_FAILURE;
	}

	while(1)
	{
		/**
			LESE den kontostand
		*/
			

		size_t readSize = sizeof(readBuffer);
		ssize_t errSizeRead = read(mainSocket, readBuffer, readSize);
		if(errSizeRead < 0)
		{
			printf("ERROR, in read(..)");
		}
		if(errSizeRead == 0)
		{
			printf("Server hat Verbindung getrennt . . \n");
			break;
		}
	

		printf("\n############################################\n");
		printf("%s\n", readBuffer);
		printf("############################################\n\n");

		/** 
			nutzerEINGABE und SENDEN
		*/
		printf("Wähle aus folgenden Optionen aus:\n0 = Disconnect\n1 = Kontogutschrift\n2 = Kontoausgabe\n");
		scanf("%d", &opt);
		
		if(opt == 0)
		{
			break;
		}
		else if(opt == 1)
		{
			strOption = '+';
		}
		else if(opt == 2)
		{
			strOption = '-';
		}
		else
		{
			printf("Keine gültige Option ausgewählt!\n");
			continue;
		}

		printf("Gebe einen Betrag ein, der mit dem Konto verrechnet werden soll:\n");
		scanf("%d", &betrag);
		
		
		sprintf(strSend, "%c%d", strOption, betrag);

		size_t sendSize = sizeof(strSend);
		ssize_t errSizeWrite = write(mainSocket, strSend, sendSize);
		if(errSizeWrite < 0)
		{
			printf("ERROR, in write(..)");
		}
	}


	err = close(mainSocket);
	if(err < 0)
	{
		printf("ERROR, mainSocket kann nicht geschlossen werden");
	}

	return EXIT_SUCCESS;

}
