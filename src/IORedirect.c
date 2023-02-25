#include <stdio.h>
#include <unistd.h>
#include "../lib/cons.h"

void IORedirect(struct CommandInput command) {
	
	/* opens files and creates/returns handles so they can be used elsewhere */

	if (command.op == '>') {
		FILE* outfile = fopen(command.outfile, "w");
		dup2(fileno(outfile), 1);
		fclose(outfile);

	}else if (command.op == '<') {
		FILE* infile = fopen(command.outfile, "r");
		dup2(fileno(infile), 0);
		fclose(infile);
	}

}
