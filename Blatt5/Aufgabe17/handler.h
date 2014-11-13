#ifndef __handler__
#define __handler__

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "unp_readline.h"

int manager(FILE * datastream, char *information);

#endif