// a hang man game inplamented in the console. If I can do this then I am good at strings ;P
/*

	How this will work:
		Get Secret Word form user
			Make sure it is only one word
				Strrchr space
					replace with null
		Set up working string
			find the useful length of secret word
			dynamically aloccate working string to the right length
			set it's length
			copy in the word
		Get guess from user
			Output a list of all of the charichters they have not yet used
				A string of the alphabet. Whenever a charichter is used remove it from string
			Output the hint for the user (ie a string of #'s showing the letters they are yet to guess
				e.g. if the strng was linux and they had guessed the i and the x: #i##x
			Ask for guess
			Validate guess (should be in loop)
				Cut down to one charichter
				Check is a letter (ctypes.h)?
				Look to see if this has allready been used
		Process Guess
			Remove guessed charichter from the unused letters array
				char* UpdateUnused(char* old, int* length, char letter to go)
					dynamically allocate new array of the correct size
					make char* new point to it
					coppy old length to new variable
					set the value for new length (using pointer to the external length
					transfer charichters from old to new
						find the letter to go
						for loop for the index in the new array
							transfer all letters before it (for loop through old)
							transfer all letters after it (for loop through old)
					free the old array
					return address of new array
						example usage:
							UnusedLetters=UpdateUnused(UnusedLetters, length, guess)
							this will make UnusedLetters point to the new array 
								and update the length
		 	Add charichter to the user hint
				void UpdateHint(char* working string, int working length, char* hint, int length hint)
					while (there are occurences of that charichter in the WORKING STRING)
						Find first occurance in that string (strchr)
						Put the guess charichter at that index in the hint
						replace that charichter in the working string with a "*"
			Is there a winner?
				decriment number of guesses
					if that is less than a const then word person wins
				is the working string only *'s?
					for loop through
						if not a * or NULL then change a bool
					if the bool was not changed then is all *'s
					if so then the guesser has won :-)
		FREE EVERYTHING!!!!!!!
			Working string
			Unused Charichters

*/
#include <stdio.h>
#include "init.h"
#include <stdlib.h> // for free

int main(void){
	char sSecretWord[20] = {0};
	char* sWorkingString = 0; // NULL so that it cannot be used yet
	int iWorkingStringLength = 0; // stores the length pointed to by ^^^ IS THIS NESSECARY FOR A STRING??

	printf("Please enter the secret word\t");
	getWord(sSecretWord,sizeof(sSecretWord));
	printf("The word you entered was %s\n", sSecretWord);

	sWorkingString = createWorkingString(sWorkingString, sSecretWord, &iWorkingStringLength);
	printf("The working string is %s\n", sWorkingString);
	printf("The size of sSecretWord is %i. The size of the working string is %i\n", sizeof(sSecretWord), iWorkingStringLength);

	free(sWorkingString);
	sWorkingString = NULL; // good practice to allways make it NULL after a free. NO MATTER WHAT!
	return 0;
}
