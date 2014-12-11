.section .data					# Startet den Datenteil für Konstanten und vordefinierte Werte

str:    .ascii  "Hello world!\n"		# Definiert eine Zeichenfolge im ASCII-Format mit "Hello world!"
        strlen = . - str			# Aktuelle Position - Start der Sprungmarke = Laenge des Textes

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
       
	movl $1, %eax      				# Befehl "terminiere"
	movl $0, %ebx      				# Rueckgabewert 0
	int  $0x80					# Kontrolle ans Betriebssystem => Wir sind durch
