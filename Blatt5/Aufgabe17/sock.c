#include "sock.h"

int serversocket = 0;

int prepare_socket(int portnum)
{
  int error;

  struct sockaddr_in addr;

  serversocket = socket(AF_INET,SOCK_STREAM,0);

  if(serversocket < 0)
  {
  	return 0;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(portnum);
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

int manage_connections(int anzverbindungen, int (*managerfunction) (FILE * datastream, char *information))
{
  int new_sock,i;
  struct sockaddr_in addr;

  socklen_t addrlen = sizeof(struct sockaddr_in);


for(i=0;i<anzverbindungen;i++)
{
  new_sock = accept(serversocket, (struct sockaddr*) &addr, &addrlen);

  if(new_sock < 0)
  {
  	printf("Verbindungsaufbau fehlgeschlagen\n");
  	//return -1;
  }
  else
  {
  	printf("Verbindung aufgebaut\n");
  	FILE *stream;
  	stream = fdopen(new_sock, "r+");
  	managerfunction(stream, inet_ntoa(addr.sin_addr));
    if(stream != NULL && fclose(stream) == 0)
    {
      close(new_sock);
      printf("Verbindung wurde beendet\n");
    }
  }
}

return anzverbindungen;
}