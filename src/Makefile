CC=gcc
CFLAGS = -Wall

default: shell

shell: main.o ParseCommandLineInput.o ExecuteCommand.o 
	$(CC) $(CFLAGS) -o shell ../obj/main.o ../obj/ParseCommandLineInput.o ../obj/ExecuteCommand.o 

main.o: main.c ../lib/cons.h ../includes/ParseCommandLineInput.h ../includes/ExecuteCommand.h
	$(CC) $(CFLAGS) -o ../obj/main.o -c main.c

ExecuteCommand.o: ExecuteCommand.c ../lib/cons.h 
	$(CC) $(CFLAGS) -o ../obj/ExecuteCommand.o -c ExecuteCommand.c

ParseCommandLineInput.o: ParseCommandLineInput.c ../lib/cons.h
	$(CC) $(CFLAGS) -o ../obj/ParseCommandLineInput.o -c ParseCommandLineInput.c

clean:
	$(RM) shell ../obj/*
