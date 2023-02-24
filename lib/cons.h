#ifndef LIB
/* All predefined values should be in here */


/* change the value to 1 for debug mode */
#define DEBUG 0


/* base number to be used to allocate memory onto the heap */
/* trying to reduce the number of resizes */
#define BASE_AMOUNT_OF_INPUT_STORAGE 10


/* contains */ 
/*  - a char[][] for storing each token argument value in a different array*/
typedef char inputString[BASE_AMOUNT_OF_INPUT_STORAGE][30];


/* rough construct of what a command should look like */
/* should contain */
/*	- the commmand */
/*	- the args stored in a array */
struct CommandInput {
	char* command;
	char** args;

};


#endif
