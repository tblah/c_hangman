// this file contains the functions nessecary for processing the guess

#include <string.h> // for strlen and strchr
#include <stdlib.h> // for dynamic memmory

int numLeftToGuess(char* s){ // returns the number of '#'s in the string (i.e. the number of letters left
	int iNumLeft = 0; // used as bool
	int i = 0;

	for (i=0; i <= strlen(s);i++) // loop through whole string
		if (s[i] == '#')
			iNumLeft++; // '#' signifies a letter which has not been guessed.
	
	return iNumLeft;
}

char UpdateHint(char* sWorkingString, char* sHint, char cGuess){ // returns true if the guess was correct
	char* cpLocation = NULL;

	if (strchr(sWorkingString, cGuess) == NULL) // if it ain't in the word, don't bother searching
		return 0;

	while (1 == 1){
		// while there are still occurances of the guess in working string
		cpLocation = NULL;

		cpLocation = strchr(sWorkingString, cGuess);
		if (cpLocation == NULL) 
			break; // letter not found so leave the loop
		

		// put the guess charichter at that index in the hint:
		int iIndex = cpLocation - sWorkingString;
		sHint[iIndex] = *cpLocation;		

		// replace the charichter in the working string with a '*'
		*cpLocation = '*';

	}
	return 1;
}

char* UpdateUnused(char* sOld, const char ccGuess){
	char* sNew = NULL; // so that it cannot be used
	int iSize = (strlen(sOld))+1; // strlen only returns the number of CHARICHTERS. 
	char* pcLocation = strchr(sOld, ccGuess);
	char* pcNewCounter = NULL; // for counting through the new string
	char* pcOldCounter = NULL; // for counting through the old string

	sNew = malloc(iSize-1); // the adding and taking away 1 could be removed but it makes this clearer
	pcNewCounter = sNew; // so the loop starts on the first charichter of sNew

	for (pcOldCounter = sOld; pcOldCounter < pcLocation; pcOldCounter++){ // itterate through until the charichter to go
		*pcNewCounter = *pcOldCounter;
		pcNewCounter++;
	} // ... miss out pcLocation
	for (pcOldCounter = pcLocation + 1; pcOldCounter <= (sOld + iSize); pcOldCounter++){
		*pcNewCounter = *pcOldCounter;
		pcNewCounter++;
	}
	
	free(sOld);
	return sNew;
}
