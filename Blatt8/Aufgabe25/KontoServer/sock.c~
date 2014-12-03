#include "sock.h"

int serversocket = 0;
int clients[99];
int konto[16];
int kontoLock[16];

int prepare_socket(int port)
{
  int error;

  struct sockaddr_in addr;

  serversocket = socket(AF_INET,SOCK_STREAM,0);

  if(serversocket < 0)
  {
  	return 0;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr =htonl(INADDR_ANY);

  error = bind(serversocket,(struct sockaddr *) &addr, sizeof(struct sockaddr_in));

  if(error < 0)
  {
    printf("binden des Sockets fehlgeschlagen\n");
    close(serversocket);
    serversocket = 0;
  	return 0;
  }

  error = listen(serversocket, 1);

  if(error < 0)
  {
  	printf("fehler beim listen des Sockets\n");
    close(serversocket);
    serversocket = 0;
  	return 0;
  }

  //alles hat funktioniert
  return 1;
}

void close_socket(void)
{
  if(close(serversocket)<0)
  {
    printf("schließen des Sockets fehlgeschlagen\n");
  }
  serversocket = 0;
  return;
}

int manage_connections()
{
  int new_sock, err;
  fd_set rset;
  struct sockaddr_in addr;

  socklen_t addrlen = sizeof(struct sockaddr_in);

char writeBuffer[9999];
char readBuffer[9999];

int i = 0;
while(i < 99)
{
	clients[i] = -1;
	i++;
}
i = 0;
while (i < 16)
{
	konto[i] = 0;
	kontoLock[i] = -1;
	i++;
}

while(1)
{
	FD_ZERO(&rset);
	FD_SET(serversocket, &rset);
	int highest_fd = serversocket;

	i = 0;
	while(i < 99)
	{
		if(clients[i] != -1)
		{
			FD_SET(clients[i], &rset);
			if(clients[i] > highest_fd)
			{
				highest_fd = clients[i];
			}
		}
		i++;
	}	


	err = select(highest_fd + 1, &rset, NULL, NULL, NULL);
	if(err < 0)
	{
		printf("ERROR bei seelct(..)\n");
	}
	if(FD_ISSET(serversocket, &rset))
	{
		new_sock = accept(serversocket, (struct sockaddr*) &addr, &addrlen);
		if(new_sock < 0)
		{
			printf("Verbindungsaufbau fehlgeschlagen\n");
		 	return -1;
		 }
		 else
		 {
		 	printf("Verbindung aufgebaut\n");
			i = 0;				
			while(i<99)
			{
				if(clients[i]==-1)
				{
				clients[i] = new_sock;
				sprintf(writeBuffer, "Willkommen, wähle eine Kontonummer aus (0-15)\n");
				size_t sendSize = sizeof(writeBuffer);
				ssize_t errSizeWrite = write(clients[i], writeBuffer, sendSize);
				if(errSizeWrite < 0)
				{
					printf("senden fehlgeschlagen\n");
					return EXIT_FAILURE;
				}
				break;
				}
				i++;
			}
		  }
	}


	i = 0;
	while(i<99)
	{		
		if(FD_ISSET(clients[i], &rset))
		{
			size_t readSize = sizeof(readBuffer);
			ssize_t errSizeRead = read(clients[i], readBuffer, readSize);
			if(errSizeRead < 0)
			{
				printf("ERROR, in read(..)\n");
			}
			else if(errSizeRead == 0)
			{
				printf("Client meldet sich ab!\n");
				close(clients[i]);
				int j = 0;
				while(j < 16)
				{
					if(kontoLock[j] == clients[i])
					{
						kontoLock[j] = -1;
						printf("Konto %d ist wieder verfügbar!\n", j);
					}					
					j++;
				}
				clients[i] = -1;
			}
			else{

				printf("gelesen: %s\n", readBuffer);
				
				if(readBuffer[0] == '#')
				{
					printf("Client will ein neues Konto locken!\n");
					char substr[2];
	//TODO
					sprintf(substr, "%c%c", readBuffer[1], readBuffer[2]);
					int lockKonto = atoi(substr);
					printf("lockKonto : %d\n", lockKonto);
					sprintf(writeBuffer, "- Konto wurde schon reserviert! Versuch es später erneut!\n");
					if(lockKonto < 0 || lockKonto > 15)
					{
						sprintf(writeBuffer, "- Kontonummer nicht gültig! Bitte kültiges Konto wählen\n");
					}
					else if(kontoLock[lockKonto] == -1)
					{
						kontoLock[lockKonto] = clients[i];
						sprintf(writeBuffer, "+ Konto erfolgreich reserviert! Kann jetzt bearbeitet werden!\n");
					}
					size_t sendSize = sizeof(writeBuffer);
					ssize_t errSizeWrite = write(clients[i], writeBuffer, sendSize);
					if(errSizeWrite < 0)
					{
						printf("senden fehlgeschlagen\n");
						return EXIT_FAILURE;
					}

					if(writeBuffer[0] == '-')
					{
						printf("Socket geschlossen -> ungültiges Konto\n");
						close(clients[i]);
					}
					else
					{
						sprintf(writeBuffer, "Ihr aktueller Knotstand (Konto %d) beträgt : %d", lockKonto, konto[lockKonto]);
						size_t sendSize = sizeof(writeBuffer);
						ssize_t errSizeWrite = write(clients[i], writeBuffer, sendSize);
						if(errSizeWrite < 0)
						{
							printf("senden fehlgeschlagen\n");
							return EXIT_FAILURE;
						}
					}

				}
				else
				{

					int kontoChange = atoi(readBuffer);
					printf("Folgende Änderung: %d\n", kontoChange);

					int j = 0;
					while(j < 16)
					{
						if(kontoLock[j] == clients[i])
						{
							konto[j] += kontoChange;
							printf("neuer Kontostand bei Konto %d: %d\n", j, konto[j]);

							sprintf(writeBuffer, "Ihr neuer Knotstand (Konto %d) beträgt : %d\n", j, konto[j]);
							size_t sendSize = sizeof(writeBuffer);
							ssize_t errSizeWrite = write(clients[i], writeBuffer, sendSize);
							if(errSizeWrite < 0)
							{
								printf("senden fehlgeschlagen\n");
								return EXIT_FAILURE;
							}
							
						}
						j++;
					}
				}


			

			}
		}
	i++;
	}

}

return 1;
}
