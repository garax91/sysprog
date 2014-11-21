#ifndef __sock__
#define __sock__

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int prepare_socket(int portnum);
void close_socket(void);
int manage_connections();

#endif
