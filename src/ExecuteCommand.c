#include "../lib/cons.h"
#include <unistd.h>
#include "../src/ParsecommandLineInput.c"

void ExecuteCommand(struct CommandInput command) {
 int status_code = execvp()
 
 if (status_code == -1){
  printf("Process did not terminate correctly\n")
  exit(1);
 }
 
  
  
  
  
  /* process the tokens and then look for I/O redirects */
	/* for (char *parsedIterator = 0; *parsedIterator < numTokens - 1; parsedIterator++) { */
	/* 	if (parsedInput[*parsedIterator] == '>' || parsedInput[*parsedIterator] == '<') { */
	/* 		FILE* file = IORedirect(parsedInput[*parsedIterator]); */

	/* 		/1* do stuff *1/ */

	/* 		fclose(file); */

	/* 		break; */
	/* 	} */
	/* } */

	/* parsedInput should always have a command in the first spot */
	/* followed by parameters */

}
