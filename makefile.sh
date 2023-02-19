#!/bin/bash


# build all of the object files
gcc -c main.c -Wall -o obj/main.o
gcc -c includes/definitions/CommandLine.c -Wall -o obj/CommandLine.o
gcc -c includes/definitions/IORedirect.c -Wall -o obj/IORedirect.o
gcc -c includes/definitions/ExecuteCommand.c -Wall -o obj/ExecuteCommand.o
gcc -c includes/definitions/ParseCommandLineInput.c -Wall -o obj/ParseCommandLineInput.o


# the final compile 
gcc -o shell obj/main.o obj/CommandLine.o obj/IORedirect.o obj/ParseCommandLineInput.o obj/ExecuteCommand.o
