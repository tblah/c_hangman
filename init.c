// see main.c for a program description

// this file contains functions for starting the game (stuff that comes before the main game loop)

#include <stdio.h>
#include <stdlib.h> // for exit() and malloc()
#include <string.h> // for strchr() and memmove() and strlen()
#include <assert.h> // for assert()
#include <ctype.h> // for isspace() and toupper()

char isAllAlpha(char* s){
	int i = 0; // for itterating through the string
	char bAllAlpha = 1; // start assuming that they are all alpha

	while (1){ // infinite loop
		if (s[i]=='\0')
			break; // end of string so stop

		if (isalpha(s[i]) == 0) { // if it is not an alphabetic charichter
			bAllAlpha = 0; // make this false
			break; // no need to continue checking
		}
	i++;
	}
	return bAllAlpha;
}

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
	while (1){ // infinite loop until broken by a valid input
		printf("Please enter the secret word\t");
		if (fgets( s, length, stdin) == NULL){ // get the string
			printf("\nERROR: fgets() in getWord() in init.c returned NULL. Cowardly refusing to continue.\n");
			exit(-1);
		}

		stripLeadingSpaces(s); // remove all leading spaces from s 
		replaceChar(s, ' '); // make the string end at the first space
		replaceChar(s, '\n'); // remove any newlines
		makeUpper(s); // make every letter uppercase

		if (isAllAlpha(s) == 1) // if every charichter in the string is either NULL or alphabetic
			break;
		else
			printf("Your word can only contain letters\n");
	}

}

char* createWorkingString(char* cpPointer,const char* sWord){ // like realloc but I need to keep the origional
	int length = strlen(sWord); // find the length of sWord until the first NULL (this is the useful part)
	cpPointer = malloc(length); // allocate a string of the right length
	assert(cpPointer); // ensure that cpPointer is not NULL
	memmove(cpPointer, sWord, length); // copy the data into the secret word 
	return cpPointer;
}

