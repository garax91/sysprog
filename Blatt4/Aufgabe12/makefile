CPPFLAGS = -g -Wall
OBJECTS = my_func.o host_zu_ip.oo
DEPS =  network_tools.h


%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CPPFLAGS) 

network_ip: $(OBJECTS)
	gcc -o $@ $^ $(CPPFLAGS)
