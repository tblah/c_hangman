// see main.c for a program description

// this file contains functions for starting the game (stuff that comes before the main game loop)

#include <stdio.h>
#include <stdlib.h> // for exit() and calloc()
#include <string.h> // for strchr() and memmove() and strlen()
#include <assert.h> // for assert()
#include <ctype.h> // for isspace()

void stripLeadingSpaces(char* s){
	/* used to count through the array to find the first charichter that is not a space*/
	char* pcPosCounter = s;
	
	assert(s); // make sure s is not NULL
	/* keep counting through the array untll either NULL or a value which is not a space is encountered */	
	while (*pcPosCounter != '\0' && isspace(*pcPosCounter)){
		++pcPosCounter;
	}
	/* move the charichters from after the spaces to the begginning of the string */
	memmove(s, pcPosCounter, strlen(pcPosCounter));	
}

void replaceChar(char* s, char c){
	char* pcReplace = 0; // as a NULL pointer so that it cannot be used yet

	pcReplace = strchr(s,c); // find the specified charichter
	
	if (pcReplace != NULL) // if the letter was found
		*pcReplace = 0; // replace the charichter with NULL: signifying the end of the string
}

void getWord(char* s, int length){
	if (fgets( s, length, stdin) == NULL){ // get the string
		printf("\nERROR: fgets() in getWord() in init.c returned NULL. Cowardly refusing to continue.\n");
		exit(-1);
	}

	stripLeadingSpaces(s); // remove all leading spaces from s (otherwise the string would start with a null after below
	replaceChar(s, ' '); // make the string end at the first space
	replaceChar(s, '\n'); // remove any newlines

}

char* createWorkingString(char* cpPointer,const char* sWord, int* length){ // like realloc but I need to keep the origional
	*length = strlen(sWord); // find the length of sWord until the first NULL (this is the useful part)
	cpPointer = malloc(*length); // allocate a string of the right length
	assert(cpPointer); // ensure that cpPointer is not NULL
	memmove(cpPointer, sWord, *length); // copy the data into the secret word 
	return cpPointer;
}
