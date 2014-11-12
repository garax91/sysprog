#include "handler.h"
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
  int anzverbindungen;
  int portnummer;
  
  if(argc < 3)
  {
    printf("Die anzahl an Argumenten ist nicht koreckt\n");
    return EXIT_FAILURE;
  }

  anzverbindungen = (int)argv[1];
  portnummer = (int)argv[2];

  if (!prepare_socket(portnummer)) {
    printf("Fehler beim Erzeugen / binden des Sockets\n");
    return 1;
  }
  anzverbindungen = manage_connections(anzverbindungen, &manager);
  printf("%d Verbindungen wurden behandelt.\n", anzverbindungen);
  close_socket();
  return 0;
}
  