OBJECTS = tcpserver.o handler.o sock.o
CPPFLAGS = -Wall -g
CC = gcc

run: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o run $(OBJECTS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $<
