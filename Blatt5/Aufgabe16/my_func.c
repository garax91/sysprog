#include "my_func.h"

//gibt 1 zurück wenn das system in big endian arbeiten sonst 0
int big_endian()
{
	int num = 1;

	if((*(char*)&num)==1)
	{
		return 0;
	}
		return 1;
}

char* my_inet_ntoa(struct in_addr in)
{
	unsigned long address = *(unsigned long *)&in;
	
	//allociert ein 4er arry von ints um den jeweiligen wert eines byets abzuspeichern
	int *adress_aufteilung;
	adress_aufteilung	= 	(int*)malloc(sizeof(int) * 4);	
	
	//geht die adresse byte weise durch und speichert den wert jeweils eines bytes in einm element des arrays
	int i;
	for(i=0;i<4;i++) {
		adress_aufteilung[i]		=	address % 256;
		address				=	address/256;
	}
	
	//allociert speicher für das ergebnis
	char *result;
	result					=	(char*)malloc(sizeof(char)*16);	

	//schreibt die werte je nach big oder litle endian in richtiger reihenfolge ins ergebnis
	int a = big_endian();
	if(a==1)
		snprintf(result,16, "%d.%d.%d.%d", adress_aufteilung[3], adress_aufteilung[2], adress_aufteilung[1], adress_aufteilung[0]);
	else
		snprintf(result,16, "%d.%d.%d.%d", adress_aufteilung[0], adress_aufteilung[1], adress_aufteilung[2], adress_aufteilung[3]);

	free(adress_aufteilung);
	
	return result;
}

//kurze funktion um adresse aus einem char zu genereieren
struct in_addr getIP(const char* host)
{
	struct in_addr address;
	struct addrinfo *res;


	if(getaddrinfo(host, "80", NULL, &res) == 0) {
		address.s_addr		=	((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
	}

	freeaddrinfo(res);

	return address;
}
