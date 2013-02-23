// this file contains the functions nessecary for processing the guess

#include <string.h> // for strlen
#include <stdlib.h> // for dynamic memmory

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
