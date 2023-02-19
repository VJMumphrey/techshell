#ifndef LIB

/* change the value to 1 for debug mode */
#define DEBUG 0

/* base number to be used to allocate memory onto the heap */
/* trying to reduce the number of resizes */
#define BASE_AMOUNT_OF_INPUT_STORAGE 10
/* all predefined values should be in here */

/* contains */ 
/*  - a index for enumerating through the heap */
/*  - a char[] for storing each index of input */
struct inputArray {
	short int index;
	char string[];

};

/* rough construct of what a command should look like */
/* should contain */
/*	- the commmand */
/*	- the args stored in a array */
struct CommandInput {
	char* command;
	char args[10];

};


#endif
