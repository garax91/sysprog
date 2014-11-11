#include <stdlib.h>
#include <stdio.h>
#include "my_func.h"

int main()
{
	int a = big_endian();
	//gibt aus ob das system in big oder little endian läuft
	if(a==1)
	{
		printf("Ihr System läuft in Big Endian.\n");
	}
	else
	{
		printf("Ihr system läuft in Little Endian.\n");
	}

	//alociert den speicher für die komandozeileneingabe und fragt diese ab
	const char hostname [1024];
	printf("Bitte geben sie zunächst einen Hostnamen ein zu dem die IP-Adresse bestimmt werden soll.\n");
	scanf("%s",hostname);

	struct in_addr adresse;

	adresse = getIP(hostname);

	//gibt die IP-Adresse nach zwei funktionen aus
	printf("Die zu ihrem Hostnamen %s gehörende IP-Adresse lautet:\n");
	printf("IP (inet_ntoa): %s\n", inet_ntoa(address));
	printf("IP (my_inet_ntoa): %s\n", my_inet_ntoa(address));

	free(hostname);

	return 0;
}
