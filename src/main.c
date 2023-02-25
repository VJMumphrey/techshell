#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "../lib/cons.h"
#include "../includes/ParseCommandLineInput.h"
#include "../includes/ExecuteCommand.h"


int main (void) {
	/* variables used in the program */
	char userInput[256];
	char cwdArray[50];
	char* exitCase = "exit";

	/* the main loop of the program that runs until users stops */
	while (1) {
		
		/* gets the cwd*/
		if (getcwd(cwdArray, PATH_MAX+1)) { 
			printf("%s$ ", cwdArray);
		}else{
			printf("error at printing cwd\n %s", strerror(errno));
		}


		/* gather the user input for parsing */ 
		fgets(userInput, 50, stdin);


		/* handles the use case that a user wants to leave the shell */
		int cmpStatus = strncmp(userInput, exitCase, strlen(exitCase));
		if (cmpStatus == 0) {
			exit(0);
		}

		/* used to keep track of reallocations/size on the heap */
		int heapSize = BASE_AMOUNT_OF_INPUT_STORAGE;

		/* build an array of strings on the heap */
		char** parsedInput = (char**)malloc(BASE_AMOUNT_OF_INPUT_STORAGE * sizeof(char*));

		for (int i = 0; i < BASE_AMOUNT_OF_INPUT_STORAGE; i++) {
			parsedInput[i] = malloc(100 * sizeof(char)); 
		}

		/* parse the commandline input */
		struct CommandInput command = ParseCommandLineInput(userInput, parsedInput, &heapSize);

		/* execute the command with the given the args */
		ExecuteCommand(command, &heapSize);

		/* free all of the memory */
		for (int i = 0; i < heapSize; i++) {
			free(parsedInput[i]);
		}

		free(parsedInput);

	}
	
	return 0;
}
