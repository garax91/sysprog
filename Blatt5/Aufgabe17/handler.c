#include "handler.h"

//schneidet 'whietspace' am anfang und am ende einer zeile ab
static char * trim(char * s) {
    int l = (int)strlen(s);
    
    while(l > 0 && isspace(s[l - 1])) --l;
    while(* s && isspace(* s)) ++s, --l;
    
    return strndup(s, l);
}

//überprüft ob eine zeile leer ist
static int emptyline(char* s) {
    char* test = trim(s);
    if (strlen(test) == 0) {
        free(test);
        return 1;
    }
    free(test);
    return 0;
}

//überprüft ob die anfrage korckte ist
char* validate(FILE * datastream) 
{
	//strings die zurückgegeben werden könnten
    char* err500 = "HTTP/1.1 500 Invalid request\nContent-Type: text/plain\n\nERROR 500\n";
    char* err505 = "HTTP/1.1 Version Not Supported\nContent-Type: text/plain\n\nERROR 505\n";
    char* err400 = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nERROR 400\n";
    
    //list eine zeile auf und speichert sie lockal ab
    char* zeile = (char*)malloc(MAXLINE);
    fgets(zeile, MAXLINE, datastream);
    
    //socht im datastrym nach GET und gibt einen fehler zurück falls diese nciht gefunden wird
    if (strcmp(strtok(zeile, " "), "GET") != 0) {
        
        fputs(err500, datastream);
        printf("500\n");
        free(zeile);
        return NULL;
    }
    
    //zerlegt erst den string in tockens nach " " und gibt eine Fehlermeldung zurück falls diese Zerlegung leer ist 
    char* pathpos = strtok(NULL, " ");
    if (pathpos == NULL) {
        fputs(err400, datastream);
        printf("400\n");
        free(zeile);
        return NULL;
    }
    
    //speichert den in pathpos zerlegten string in path ab zum weiter verarbeiten
    char* path = (char*)malloc(strlen(pathpos) + 1);
    strcpy(path, pathpos);
    
    //überprüft dne getrimmten nach '\n' zerlegten sting auf "HTTP/1.1" und gibt eine'Fehlermeldung zurück falls dies nciht erfüllt ist
    char* test = strtok(NULL, "\n");
    if (strcmp(trim(test), "HTTP/1.1") != 0) {
        fputs(err505, datastream);
        printf("%s\n", test);
        free(zeile);
        return NULL;
    }
    
    fgets(zeile, MAXLINE, datastream);
    //gibt fehlermeldung zurück falls kein host angegeben ist
    if (strstr(zeile, "Host: ") != zeile) {
        fputs(err400, datastream);
        printf("400\n");
        free(zeile);
        return NULL;
    }
    
    *strstr(zeile, "\n") = '\0';
    
    //trimt den path und schreibt in uri den host und den path rein
    path = trim(path);
    char* host = trim(zeile + 5);
    int urilen = 7 + (int)strlen(host) + (int)strlen(path) + 1;
    char* uri = (char*)malloc(urilen);
    snprintf(uri, urilen, "http://%s%s", host, path);
    
    //frees und rückgabe
    free(zeile);
    free(path);
    return uri;
}

int manager(FILE * datastream, char *information)
{
	char* zeile = (char*)malloc(10000);
    
    //überprüft ob 
    char* uri = validate(datastream);
    if (uri == NULL) {
        return 0;
    }
    
    while(fgets(zeile, MAXLINE, datastream), emptyline(zeile) == 0) {
        printf("%s", zeile);
    }
    
    //bildet die informationen die zurückgegeben werden
    fputs("HTTP/1.1 200 OK\nContent-Type: text/plain\n\n", datastream);
    fputs("Anfrage entgegengenommen\n", datastream);
    fputs("Ressource: ", datastream);
    fputs(uri, datastream);
    fputs("\nClient ID: ", datastream);
    fputs(information, datastream);
    fputs("\n", datastream);
    
    return 0;
}