#ifndef LIB
#define LIB
/* All predefined values should be in here */


/* change the value to 1 for debug mode */
#define DEBUG 0


/* base number to be used to allocate memory onto the heap */
/* trying to reduce the number of resizes */
#define BASE_AMOUNT_OF_INPUT_STORAGE 10

/* value that should be used to keep track of the current amount */
/* of allocated storage */
#define CURRENT_STORAGE = BASE_AMOUNT_OF_INPUT_STORAGE

/* rough construct of what a command should look like */
/* should contain */
/*	- the commmand */
/*	- the args stored in a array */
struct CommandInput {
	char* command;
	char** args;
	char op;
	char* outfile;

};

#endif
