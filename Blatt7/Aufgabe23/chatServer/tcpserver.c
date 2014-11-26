#include "sock.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  int port;
  
  if(argc < 2)
  {
    printf("Die anzahl an Argumenten ist nicht koreckt\n");
    return EXIT_FAILURE;
  }

  port = atoi(argv[1]);

  if (!prepare_socket(port)) {
    printf("Fehler beim Erzeugen / binden des Sockets\n");
    return 1;
  }

  printf("hört jetzt zu.\n");

  manage_connections();
  //printf("%d Verbindungen wurden behandelt.\n", anzverbindungen);
  close_socket();
  return 0;
}
  
