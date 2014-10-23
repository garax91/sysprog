OBJECTS = main.o genListe.o genString.o Person.o
CPPFLAGS = -Wall -g
CC = gcc

run: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o run $(OBJECTS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $<
