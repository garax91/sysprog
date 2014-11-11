#ifndef __my_func__
#define __my_func__

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int big_endian();
char* my_inet_ntoa(struct in_addr in);
struct in_addr getIP(const char* host);

#endif