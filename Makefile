CC = gcc
CFLAGS = -W -Wall
TARGET = login
OBJECTS = main.o menu.o user.o

all : $(TARGET) 

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c
	$(CC) $(CFLAGS) -c -o $@ $^

menu.o : menu.c
	$(CC) $(CFLAGS) -c -o $@ $^

user.o : user.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm *.o login

