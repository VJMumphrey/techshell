#include <stdio.h>
#include "../lib/cons.h"
#include "../includes/IORedirect.h"

void ExecuteCommand(struct CommandInput command) {
	/* process the tokens and then look for I/O redirects */

	if (command.op) { 
		FILE* file = IORedirect(command.op);

		/* do stuff */

		fclose(file);
	}

}
