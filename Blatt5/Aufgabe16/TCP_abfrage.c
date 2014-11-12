#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_func.h"
#include "unp_readline.h"

//definiert Buffer-Größen
#define BUFFER_SIZE 10000
#define BUFFER_LINE 100000

//gibt o zurück falls die strings gleich sind
int compare_string(char *str1, char *str2){
	while(*str1 != '\0' && *str2 != '\0' && *str1 != '\n' && *str2 != '\n'){
		if(*str1 == *str2){
			str1++;
			str2++;
		}
		else{
			if(*str1 < *str2){
				return -1;		//str1 ist 'kleiner'
			}
			else{
				return 1;		//str2 ist 'kleiner'
			}
		}
	}
	return 0;					//strings sind gleich
}

int main(int argc, char const *argv[])
{
	//öfnet einen socket für die später folgende tcp verbindung und schreibt etwas in die console flls es nicht klappt	
	int sock;
	struct sockaddr_in target;
	sock	=	socket(AF_INET,SOCK_STREAM,0);
	if(sock<0) {
		printf("ERROR Opening Socket\n");
		return 1;
	}	

	//gibt dem socket die benötigten parameter für die verbindung
	target.sin_family	= AF_INET;
	target.sin_port		= htons(80);
	target.sin_addr		= getIP("net.cs.uni-bonn.de");

	printf("# Baue Verbindung zu Webserver net.cs.uni-bonn.de auf...\n");	

	//gibt einen fehler aus falls keine verbindung hergestellt werden konnte und schließt den socket
	if(connect(sock,(struct sockaddr *)&target,sizeof(struct sockaddr_in))<0) {
		printf("ERROR Connect\n");
		close(sock);
		return 1;
	}

	printf("# Connected!\n");

	//erstellt einen buffer zum auslesen der website.
	char buffer[]		=	"GET /de/wg/cs/lehre/ws-201415/sysprog/ HTTP/1.1 \r\nHost:net.cs.uni-bonn.de\r\n\r\n";

	printf("# Schicke GET Request an Webserver");
	

	int count		=	write(sock, buffer, sizeof(buffer));	
	
	if(count<0) {
		printf("ERROR write\n");
		close(sock);
		return 1;
	}

	if(count<sizeof(buffer)) {
		printf("Nicht alle Daten gesendet\n");
	}
    
    int infos	=	1;
    int content	=	0;
    int found = 0;

	char readbuffer[BUFFER_SIZE];
	char completebuffer[1000000];
	strcpy(completebuffer, "");
	//whileschleife geht die website durch solange die zeile nicht 0 lang ist
	while(readline(sock, readbuffer, sizeof(readbuffer))>0) {
        if(infos) {
            if(readbuffer[1]=='\n') {
                infos=0;
                printf("# Die folgenden Zettel sind aktuell verfügbar:\n\n");
            }
            else {
                printf("%s",readbuffer);
            }
        }
        //gibt die übungszettel auf der seite aus
        else {
            strcat(completebuffer,readbuffer);
            if(content) {
                //printf("%s\n\n\n\n\n",readbuffer);
                char *temp;
                //sucht nach dem String Übungsblatt im readbuffer
                temp    =   strstr(readbuffer,"Uebungsblatt");
                while(1) {
                	//sucht nahc dem strig Uebungsblatt im temporären string
                    temp    =   strstr(temp,"Uebungsblatt");
                    if(temp==NULL) break;
                    char blattbuffer[20];
                    //copiert den string in blattbuffer 
                    strncpy(blattbuffer,temp,18);
                    printf("%s\n",blattbuffer);
                    temp    =   strstr(temp,"class=");
                }
                content = 0;
                found = 1;
            }
            else {
            	//
                if(strstr(readbuffer, "Übungszettel")!=NULL && !found) {
                    int i;
                    for(i=0;i<BUFFER_SIZE;i++) readbuffer[i]='\0';
                    content	=	1;
                    continue;
                }
            }
        }
            
        int i;
        for(i=0;i<BUFFER_SIZE;i++) readbuffer[i]='\0';
	}
    
    printf("\n");
    
    //schreibt alle informationen in zettel.html
	FILE *datei;
	datei		=	fopen("zettel.html", "w");
	fputs(completebuffer, datei);
	fclose(datei);

	//schließt den socket
	close(sock);
    
    printf("# Verbindung getrennt\n");
	
	return 0;
}