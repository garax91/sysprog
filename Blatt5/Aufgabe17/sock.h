#ifndef __sock__
#define __sock__

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int prepare_socket(int portnum);
void close_socket(void);
int manage_connections(int anzverbindungen, int (*managerfunction) (FILE * datastream, char *information));

#endif