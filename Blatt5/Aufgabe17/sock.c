

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

  error = bind(fd,(struct sockaddr *) &addr, sizeof(sockaddr_in));

  if(error < 0)
  {
  	return 0;
  }

  error = listen(serversocket, 1);

  if(error < 0)
  {
  	printf("sacre blööööö!\n");
  	return 0;
  }

  //alles hat funktioniert
  return 1;
}

void close_socket(void)
{
  close(serversocket);
  return;
}

int manage_connections(int anzverbindungen, int (*managerfunction) (FILE * datastream, char *information))
{
  int new_sock,i;
  struct sockaddr* addr;

  socklen_t* addrlen = sizeof(addr);


for(i=0;i<anzverbindungen;i++)
{
  new_sock = accept(serversocket, addr, addrlen);

  if(new_sock < 0)
  {
  	printf("sacre bläääää!\n");
  	return -1;
  }
  esle
  {
  	printf("");
  	File *stream;
  	stream = fdopen(new_sock, "r+");
  	managerfunction(stream, int_nota(addr.in_addr);
  }
}

return anzverbindungen;
}