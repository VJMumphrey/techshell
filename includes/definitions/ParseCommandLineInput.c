#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "../headers/IORedirect.h"
#include "../headers/cons.h"


struct CommandInput ParseCommandLineInput(char userInput[]) {
	int numTokens = 0;
	struct CommandInput command;

	char *parsedInput = malloc(sizeof(struct inputArray) * BASE_AMOUNT_OF_INPUT_STORAGE);
	char* token = strtok(userInput, " ");

	while (token != NULL) {
		token = strtok(NULL, " ");

		if (parsedInput) {
			parsedInput[numTokens] = *token;
			
		}else {
			printf("Error in allocating the parsedInput to the heap %s", strerror(errno) );
			exit(1);
		}

		/* TODO setup error handling to stop overindexing */
		if (numTokens == BASE_AMOUNT_OF_INPUT_STORAGE) {
			/* setup realloc(void *, unsigned long); to add more memory to the block on the heap */

		}
		numTokens += 1;
	}

	if (DEBUG == 1 && token == NULL) {
		printf("Error with parsing the tokens %s", strerror(errno));
		exit(1);
	}

	/* process the tokens and then look for I/O redirects */
	for (int *parsedIterator = 0; *parsedIterator < numTokens - 1; parsedIterator++) {
		if (parsedInput[*parsedIterator] == '>' || parsedInput[*parsedIterator] == '<') {
			FILE* file = IORedirect(parsedInput[*parsedIterator]);

			/* do stuff */

			fclose(file);

			break;
		}
	}

	/* parsedInput should always have a command in the first spot */
	/* followed by parameters */
	
	return command;
}
