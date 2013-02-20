// see main.c for a program description

// this file contains functions for starting the game (stuff that comes before the main game loop)

#include <stdio.h>
#include <stdlib.h> // for exit() and malloc()
#include <string.h> // for strchr() and memmove() and strlen()
#include <assert.h> // for assert()
#include <ctype.h> // for isspace() and toupper()

void makeUpper(char* s){
	int i = 0; // for counting in the loop bellow

	while (1){ // infinite loop
		if (s[i]=='\0')
			break; // if we have reached the end of the string then exit the loop
		s[i] = toupper(s[i]); // make the charichter upper case.
		i++;
	}	
}

char* allocHint(const int iSize){
	char* sHint = 0;
	int i = 0; // to itterate through the loop bellow
	
	sHint=malloc(iSize); // allocate enough memmory for the string
	assert(sHint); // make sure it didn't fail
	
	for (i=0; i<(iSize-1); i++)
		sHint[i] = '#'; // make all of the values in the string (except the last one) be '#'

	sHint[iSize-1] = '\0'; // make the last charichter in the string NULL
	

	return sHint;
}

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

void replaceChar(char* s, char c){ // replaces the first c in s with NULL
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
	makeUpper(s); // make every letter uppercase

}

char* createWorkingString(char* cpPointer,const char* sWord, int* length){ // like realloc but I need to keep the origional
	*length = strlen(sWord); // find the length of sWord until the first NULL (this is the useful part)
	cpPointer = malloc(*length); // allocate a string of the right length
	assert(cpPointer); // ensure that cpPointer is not NULL
	memmove(cpPointer, sWord, *length); // copy the data into the secret word 
	return cpPointer;
}

