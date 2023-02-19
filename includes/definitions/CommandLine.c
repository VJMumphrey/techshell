#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../headers/cons.h"
#include "../headers/ParseCommandLineInput.h"
#include "../headers/ExecuteCommand.h"


void CommadLine () {
	/* variables used in the program */
	char userInput[256];
	char pathArray[50];
	char *exitCase = "exit";
	
	/* the main loop of the program that runs until users stops */
	while (1) {
		
		/* gets the cwd*/
		getcwd(pathArray, 50);

		printf("%s$", pathArray);

		/* gather the user input for parsing */ 
		fgets(userInput, 50, stdin);


		/* handles the use case that a user wants to leave the shell */
		int cmpStatus = strncmp(userInput, exitCase, strlen(exitCase));
		if (cmpStatus == 0) {
			exit(0);
		}

		/* take in the user input from the command line */


		/* parse the commandline input */
		struct CommandInput command = ParseCommandLineInput(userInput);


		ExecuteCommand(command);
	}
}
