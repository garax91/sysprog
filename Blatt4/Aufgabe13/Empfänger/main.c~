#include <sys/types.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>
#include <arpa/inet.h>
//#include <netdb.h>
//#include <unistd.h>
//#include <signal.h>
#include <stdio.h>
//#include <string.h>
//#include <fcntl.h>
//#include <errno.h>
//#include <sys/time.h>
#include <stdlib.h>
//#include <memory.h>
//#include <ifaddrs.h>
//#include <net/if.h>
//#include <stdarg.h>

int main()
{
	int fd, err, len;
	struct sockaddr_in addr, from;
	char msg[64];
	
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		printf("Fehler bei der Socketerstellung!\n");
		return EXIT_FAILURE;
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4711);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	err = bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("Fehler beim bind\n");
		return EXIT_FAILURE;
	}
/*	err = getsocketname(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err < 0)
	{
		printf("Fehler bei getsocketname(..)\n");
		return EXIT_FAILURE;
	}
*/

	socklen_t flen = sizeof(from);	

	len = recvfrom(fd, msg, sizeof(msg), 0, (struct sockaddr *) &from, &flen);
	if(len<0)
	{
		printf("empfangen fehlgeschlagen\n");
		return EXIT_FAILURE;
	}
	printf(">>Received %d bytes from host %s port %d:\n>>Nachricht:  %s\n", len, inet_ntoa(from.sin_addr), ntohs(from.sin_port), msg);


	//free
//	free(addr);
	return EXIT_SUCCESS;
}
