#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../lib/cons.h"
#include "../includes/IORedirect.h"

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
			
			IORedirect(command);
			
			/* run the command in a seperate process */
			int status_code = execvp(command.args[0], command.args);

			if (status_code == -1){
				printf("Process did not terminate correctly\n");
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
