#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/cons.h"

void ExecuteCommand(struct CommandInput command, int* heapSize) {

	char* PATH = getenv("PATH");
	char *envp[] = {PATH, NULL};

	/* /1* build the file path comand for execvp *1/ */
	/* char filepath[10] = "bin/"; */
	/* char* runfile = command.command; */
	/* char* runpath = strncat(filepath, runfile, 5); */

	
	/* print the args recieved from parser */
	if (DEBUG == 1) {
		/* printf("%s\n", runpath); */
		printf("size of the allocated memory %d\n", *heapSize);
		for (int i = 0; i < *heapSize; i++) {

			printf("arg@%d: %s\n", i, command.args[i]);
		}
	}

	/* run the command in a seperate process */
	int status_code = execvpe("bin/ls", command.args, envp);
 
	if (status_code == -1){
		printf("Process did not terminate correctly\n");
	}
	
}
