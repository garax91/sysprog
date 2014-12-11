.section .data					# Startet den Datenteil für Konstanten und vordefinierte Werte

str:    .ascii  "Hello world!\n"		# Definiert eine Zeichenfolge im ASCII-Format mit "Hello world!"
        strlen = . - str			# Aktuelle Position - Start der Sprungmarke = Laenge des Textes

nl: 	.ascii "\n"

num:    .long	1337				# Defniniert eine Konstante num als long mit dem Wert 1337
#---------------------------------------------------------------------------------------------------------------------------

.section .text						# Start des Programmverlaufes

.global _start						# Mache das Label Start für das Betriebssystem verfuegbar

_start:							# entspricht der main in c
	
	# Vorbereiten eines Syscalls
	movl $4, %eax					# Befehl "schreibe" (4) in Akkumulator
	movl $1, %ebx      				# FD = 1 => auf die Konsole
	movl $str, %ecx    				# Unseren Buffer str
	movl $strlen, %edx 				# Mit der passenden Laenge
	int  $0x80         				# Übergebe die Kontrolle ans Betriebssystem
       
    # Ausgabe der angegebenen zahl
	movl num, %eax
	call printnum 

	movl $1, %eax      				# Befehl "terminiere"
	movl $0, %ebx      				# Rueckgabewert 0
	int  $0x80					# Kontrolle ans Betriebssystem => Wir sind durch

#neue funktion zum ausgeben der angegebenen zahl (%eax)
type printnum, @function 
printnum:
		xorl %esi, %esi				# Zählervariable für die Anzahl der Stellen (auf 0 setzen)
	
	printnum_loop:
		movl  $0, %edx				# Alten Rest löschen
		movl  $10, %ebx				# Divisor speichern (10, weil Dezimalsystem,wie in Aufgabe angegben)
		divl  %ebx				# Teilt %eax durch 10 danach ist in %eax das Ergebnis und in %edx der Rest, den wir ausgeben wollen
		addb  $48, %dl				# Addiere 48 auf den Rest (Damit erhalten wir den passenden ASCII-Code)
		pushl %edx				# ASCII-Zeichen auf den Stack schieben
		incl  %esi
		cmpb  $0, %al				# Ist das Ergebnis der Division 0, sind wir fertig
		jz    printnum_ausgabe
		
		jmp   printnum_loop
		
	printnum_ausgabe:
		testl %esi, %esi			# Setze die Flags passend für unseren Zähler %esi
		jz    printnum_exit			# Wenn der Zähler auf Null ist, haben wir alle Zeichen ausgegeben => Ende
		decl  %esi
		
		# Ausgabe des Zeichens
		popl  (%ecx)				# Lade ein Zeichen vom Stack
		movl  $4, %eax				# Ausgabe sonst wie oben
		movl  $1, %ebx
		movl  $2, %edx
		int   $0x80
		
		jmp   printnum_ausgabe
		
	printnum_exit:
		# Ausgabe von Enter
		movl  $4, %eax
		movl  $1, %ebx
		movl  $nl, %ecx
		movl  $1, %edx
		int   $0x80
		ret