1. #include <string.h> für die strlen muss includet werden
2. #include <ctype.h> füt troupper funktion
3. zeile 19 "exit" statt 'exit'
4. zeile 21 und 22 muss von void* nach char* gecarstet werden
5. zeile 11 muss der zweite vergleichsoperator um einen veringert werden da er sonst bei n anschatt bei n-1 anfängt
6. zeile 39 kann kein vergleich zwischen strings mit == gezogen weden da die pointer verglichen werden und nciht der inhalt
   hier müsste man eine euals() funktion implementieren