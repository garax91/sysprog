all: hello_a hello_b hello_c

CC		 = gcc
CPPFLAGS = -g -Wall -D_GNU_SOURCE
OBJECTS  = 
DEPS 	 = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)
	
%.o: %.asm
	as --gstabs -o $@ $<

helloworld-a: hello_a.o
	ld -o $@ $<

helloworld-b: hello_b.o
	ld -o $@ $<
	
helloworld-c: hello_c.o
	ld -o $@ $<