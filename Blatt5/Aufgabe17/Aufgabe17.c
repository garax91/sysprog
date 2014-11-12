/******************************
 * aus tcpserver.c 
 */

// includes etc.

int main(int argc, char **argv)
{
  int anzverbindungen;
  int portnummer;
  // ...

  if (prepare_socket(portnummer)) {
    printf("Fehler beim Erzeugen / binden des Sockets\n");
    return 1;
  }
  anzverbindungen = manage_connections(anzverbindungen, &manager);
  printf("%d Verbindungen wurden behandelt.\n", anzverbindungen);
  close_socket();
  return 0;
}




/********************************
 * aus sock.c
 */

// includes etc.

int serversocket = 0;

int prepare_socket(int portnum)
{
  // ...
}

void close_socket(void)
{
  // ...
}

int manage_connections(int anzverbindungen, int (*managerfunction) (FILE * datastream, char *information))
{
  // ...
}


/*********************************
 * aus handler.c
 */

// includes etc.

int manager(FILE * datastream, char *information)
{
  // ...

}