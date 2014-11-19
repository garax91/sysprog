-t ist der parameter welcher gesetzt werden muss um auschlieslich tcp sockets angezeigt zu bekommen
	-a gegebenenenfalls für alle

-a ohne andere parameter listet alles sockets auf ohne berücksichtigung ihres status

jeweils mit ss -t :
bei laufender aufgabe 17:
State      Recv-Q Send-Q      Local Address:Port          Peer Address:Port   
ESTAB      0      0           192.168.0.120:56055       173.194.113.89:http    
ESTAB      0      0           192.168.0.120:57150       173.194.113.92:http    
CLOSE-WAIT 28     0           192.168.0.120:60184         91.189.92.11:https   
ESTAB      0      0           192.168.0.120:40648      108.160.163.109:http    
CLOSE-WAIT 1      0                     ::1:40871                  ::1:ipp

nach beendigung(strg-c) von aufgabe 17:
State      Recv-Q Send-Q      Local Address:Port          Peer Address:Port   
ESTAB      0      0           192.168.0.120:56055       173.194.113.89:http    
CLOSE-WAIT 28     0           192.168.0.120:60184         91.189.92.11:https   
ESTAB      0      0           192.168.0.120:40648      108.160.163.109:http    
CLOSE-WAIT 1      0                     ::1:40871                  ::1:ipp

der ESTAB aus zeile 10 wurde also geschlossen der aus zeile 9 jedoch erst nach ein paar minuten

nach ein paar minuten:
State      Recv-Q Send-Q      Local Address:Port          Peer Address:Port   
CLOSE-WAIT 28     0           192.168.0.120:60184         91.189.92.11:https   
ESTAB      0      0           192.168.0.120:40648      108.160.163.109:http    
CLOSE-WAIT 1      0                     ::1:40871                  ::1:ipp

rest bleibt gleich