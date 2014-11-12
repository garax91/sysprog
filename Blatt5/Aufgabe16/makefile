OBJECTS = TCP_abfrage.o my_func.o unp_readline.o
CPPFLAGS = -Wall -g
CC = gcc

run: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o run $(OBJECTS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $<
