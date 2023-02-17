#!/bin/bash

gcc -c main.c -Wall -o obj/main.o
gcc -c includes/CommandLine.c -Wall -o obj/CommandLine.o
gcc -c includes/IORedirect.c -Wall -o obj/IORedirect.o
gcc -o shell obj/main.o obj/CommandLine.o obj/IORedirect.o
