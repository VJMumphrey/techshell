#include <stdio.h>
#include <unistd.h>

FILE* IORedirect(char operator) {
	
	FILE* file;
	
	// figure out how this works to correctly implement
	if (operator == '>') {
		FILE* outfile = fopen("outfile", "w");
		dup2(fileno(outfile), 0);

		/* some code here */

		file = outfile;

	}else if (operator == '<') {
		FILE* infile = fopen("inputFile", "r");
		dup2(fileno(infile), 0);

		/* some code here */

		file = infile;
	}

	return file;
}
