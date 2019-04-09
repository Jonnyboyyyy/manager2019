CC = gcc
CFLAGS = -W -Wall
TARGET = login
OBJECTS = main.o menu.o user.o
D_OBJECTS = main_d.o menu_d.o user_d.o

all : $(TARGET) 

login_debug : $(D_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(D_OBJECTS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

clean :
	rm *.o login login_debug

