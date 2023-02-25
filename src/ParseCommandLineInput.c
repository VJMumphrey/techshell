#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "../lib/cons.h"


struct CommandInput ParseCommandLineInput(char userInput[], char** args, int* heapSize) {
	int numTokens = -1;
	struct CommandInput command;

	char* token = strtok(userInput, " ");
	int pos = strcspn(token, "\n");
    token[pos] = '\0';

	/* loops through the tokens and adds them to the parsedInput */
	while (token != NULL) {
		printf("numTokens: %d\n", numTokens);
		if (numTokens == -1) {
			command.command = token;
			numTokens += 1;
			continue;
		}

		if (args) {

			if (*token == '>' || *token == '<') {
				command.op = *token;	
				goto skip;
			}
			strcpy(args[numTokens], token);

			skip:
			if (DEBUG == 1) {
				printf("%s from parser\n", token);
			}
			
		}else {
			printf("Error in allocating parsedInput %s", strerror(errno));
			exit(1);
		}

		/* reallocate memory if the amount that is already present is full */
		if (numTokens == BASE_AMOUNT_OF_INPUT_STORAGE) {
			*heapSize += BASE_AMOUNT_OF_INPUT_STORAGE;
			args = (char**)realloc(args, *heapSize); 
		}

		token = strtok(NULL, " ");

		/* strip the \n from the token */
		if (token != NULL) {
			int pos = strcspn(token, "\n");
			token[pos] = '\0';
		}

		numTokens += 1;
	}

	/* check to reduce memory */
	args = (char**)realloc(args, (numTokens+1) * sizeof(char*));
	*heapSize = numTokens+1;

	/* append null to the end of the args list */
	/* for (int i = 0; i < *heapSize; i++) { */
	/* 	if (args[i] == 0){ */
	/* 		args[i] = NULL; */
	/* 	} */
	/* } */

	args[numTokens+1] = NULL;

	/* parsedInput should always have a command in the first spot */
	/* followed by parameters */
	/* followed by a redirection op if necessary */

	/* give the command args the pointer to the parsed input */
	command.args = args;

	return command;
}


