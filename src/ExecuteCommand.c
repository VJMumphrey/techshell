#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../lib/cons.h"

void ExecuteCommand(struct CommandInput command, int* heapSize) {

	/* print the args recieved from parser */
	if (DEBUG == 1) {
		printf("size of the allocated memory %d\n", *heapSize);
		for (int i = 0; i < *heapSize; i++) {

			printf("arg@%d: %s\n", i, command.args[i]);
		}
	}

	int cmpStatus = strncmp(command.args[0], "cd", strlen("cd"));
	if (cmpStatus == 0) {
		chdir(command.args[1]);
		return;

	}else {

	
		pid_t pid = fork();

		if (pid < 0) {
			printf("failed to fork\n %s", strerror(errno));
		}else if (pid == 0) {
			/* redirect input and output if specified */
			if (command.outfile != NULL) {
				if (command.op == '<') {

					int inputFd = open(command.outfile, O_RDONLY);
					if (inputFd == -1) {
						printf("Failed to open input file %s\n", command.outfile);
						exit(0);
					}
					dup2(inputFd, STDIN_FILENO);
				}
			}
			if (command.outfile != NULL) {
				if (command.op == '>') {
					int outputFd = open(command.outfile, O_CREAT|O_WRONLY|O_TRUNC, 0644);
					if (outputFd == -1) {
						printf("Failed to open output file %s\n", command.outfile);
						exit(0);
					}
					dup2(outputFd, STDOUT_FILENO);
				}
			}
			
			/* run the command in a seperate process */
			int status_code = execvp(command.args[0], command.args);

			if (status_code == -1){
				printf("Error in running command\n");
				printf("try using [cmd] [arguments...] [I/O] [file]\n");
				printf("eg: ls -la > out.txt\n");
				exit(0);
			}

			if (errno == ENOENT) {
				printf("Error: %s\n", strerror(errno));
				exit(0);
			}	

			if (errno == EACCES) {
				printf("Error: %s\n", strerror(errno));
				exit(0);
			}

		}else {
			wait(NULL);
			return;
		}

	}
	

	return;	
}
