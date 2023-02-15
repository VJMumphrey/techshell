#!/bin/bash

gcc -c main.c -Wall -o obj/main.o
gcc -c includes/CommandLine.c -Wall -o obj/CommandLine.o
gcc -o shell obj/main.o obj/CommandLine.o
