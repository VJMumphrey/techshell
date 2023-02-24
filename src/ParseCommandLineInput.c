#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "../lib/cons.h"


struct CommandInput ParseCommandLineInput(char userInput[], char** parsedInput) {
	int numTokens = 0;
	struct CommandInput command;

	char* token = strtok(userInput, " ");

	/* loops through the tokens and adds them to the parsedInput */
	while (token != NULL) {

		if (parsedInput) {
			if (numTokens == 0) {
				command.command = token;
			}else {
				parsedInput[numTokens] = token;
			}

			if (DEBUG == 1) {
				printf("%s ", token);
			}
			
		}else {
			printf("Error in allocating parsedInput %s", strerror(errno));
			exit(1);
		}

		/* reallocate memory if the amount that is already present is full */
		if (numTokens == BASE_AMOUNT_OF_INPUT_STORAGE) {
			char** parsedInput = (char**)realloc(parsedInput, BASE_AMOUNT_OF_INPUT_STORAGE*2); 
		}

		token = strtok(NULL, " ");
		numTokens += 1;

		/* if (DEBUG == 1 && token == NULL) { */
		/* 	printf("Error with parsing the tokens %s", strerror(errno)); */
		/* 	exit(1); */
		/* } */
	}

	/* parsedInput should always have a command in the first spot */
	/* followed by parameters */

	/* give the command args the pointer to the parsed input */
	command.args = parsedInput;

	return command;
}
