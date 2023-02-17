#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "IORedirect.h"
#include "cons.h"

/* change the value to 1 for debug mode */
#define DEBUG 0

/* base number to be used to allocate memory onto the heap */
/* trying to reduce the number of resizes */
#define BASE_AMOUNT_OF_INPUT_STORAGE 10


void CommadLine () {
	/* variables used in the program */
	char userInput[256];
	char pathArray[50];
	char cwdArray[50];
	char *exitCase = "exit";
	int numTokens = 0;
	
	/* the main loop of the program that runs until users stops */
	while (1) {
		
		/* gets the absolute path of the cwd*/
		getcwd(pathArray, 50);


		/* used to get the cwd alone from the path */
		size_t n = sizeof(pathArray) / sizeof(pathArray[0]);
		int j = 49;
		for (int index = n-1; index > 0; index--) {
			if (pathArray[index] == '/') { 
				break;	
			}

			cwdArray[j] = pathArray[index];
			j -= 1;

		}

		for (int i = 0; i < strlen(cwdArray); i++) {
			printf("%c", cwdArray[i]);
		}

		printf("$");

		/* gather the user input for parsing */ 
		fgets(userInput, 50, stdin);


		/* handles the use case that a user wants to leave the shell */
		int cmpStatus = strncmp(userInput, exitCase, strlen(exitCase));
		if (cmpStatus == 0) {
			exit(0);
		}

		/* take in the user input from the command line
		 * builds array of strings for later uses*/

		char *parsedInput = malloc(sizeof(inputArray) * BASE_AMOUNT_OF_INPUT_STORAGE);
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
		
	}


}
