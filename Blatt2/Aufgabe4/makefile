
CPPFLAGS = -g -Wall
OBJECTS  = brett.o springerproblem.o
DEPS     = brett.h

%.o : %.c &(DEPS)
	gcc -c -o %@ $< %(CPPFLAGS)

springerproblem: $(OBJECTS)
	gcc -o $@ $^ $(CPPFLAGS)
