// see main.c for a program description

// this file contains functions for starting the game (stuff that comes before the main game loop)

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h> // for strchr()

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

	replaceChar(s, ' '); // make the string end at the first space
	replaceChar(s, '\n'); // remove any newlines

}
