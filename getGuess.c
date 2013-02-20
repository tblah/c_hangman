// this file contains functions for getting a user's guess of a word from them

#include <stdio.h>
#include <ctype.h> // for isalpha() and toupper()
#include <string.h> // for strchr()

char getGuess(const char* sUnused, const char* sHint){
	char bValid = 0; // using as a boolean
	char cInput = '\0';

	printf("You have not yet used: %s\n", sUnused);
	printf("Hint: %s\n", sHint);

	while (bValid == 0){
		printf("Please enter your guess\t");
		cInput = fgetc(stdin);		
		fgetc(stdin); // remove the newline from stdin
		bValid = 1; // if neither condition is true then it must be valid

		if (!(isalpha(cInput))){
			printf("Try a letter.\n");
			bValid = 0; // try agian
		}

		if (bValid != 0) { // make sure that the above has not happened
			cInput = toupper(cInput); // now that we know that it is a letter, make sure it is uppercase		
			if (!(strchr(sUnused, cInput))){ // if the charichter has been used
				printf("You have already used this letter. Try again.\n");
				bValid = 0;
			}
		}
	}
	return cInput;
}
