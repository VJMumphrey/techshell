#include <stdio.h>
#include <unistd.h>

FILE* IORedirect(char operator) {
	
	/* opens files and creates/returns handles so they can be used elsewhere */

	FILE* file;
	
	if (operator == '>') {
		FILE* outfile = fopen("outfile", "w+");
		/* dup2(fileno(outfile), 0); */
	
		file = outfile;

	}else if (operator == '<') {
		FILE* infile = fopen("inputFile", "r");
		/* dup2(fileno(infile), 0); */

		file = infile;
	}

	return file;
}
