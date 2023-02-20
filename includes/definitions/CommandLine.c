#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "../headers/cons.h"
#include "../headers/ParseCommandLineInput.h"
#include "../headers/ExecuteCommand.h"


void CommadLine () {
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

		/* parse the commandline input */
		struct CommandInput command = ParseCommandLineInput(userInput);


		ExecuteCommand(command);
	}
}
