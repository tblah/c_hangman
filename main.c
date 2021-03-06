// a hang man game inplamented in the console. If I can do this then I am good at strings ;P
/*

	How this will work:
		while secret word is not valid
			Get Secret Word form user
				Make sure it is only one word
					Strrchr space
						replace with null
			Make it all uppercase
		If it is all alphabetical then continue. Else loop.
		Set up working string
			find the useful length of secret word
			dynamically aloccate working string to the right length
			set it's length
			copy in the word
		Get guess from user
			Output a list of all of the charichters they have not yet used
				A string of the alphabet. Whenever a charichter is used remove it from string
			Output the hint for the user (ie a string of #'s showing the letters they are yet to guess)
				e.g. if the string was linux and they had guessed the i and the x: #i##x
			Ask for guess
			Validate guess (should be in loop)
				Cut down to one charichter
				Check is a letter (ctypes.h)?
				Make it uppercase
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
				void UpdateHint(char* working string, char* hint, char cGuess)
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
#include <string.h> // for strlen
#include "getGuess.h"
#include "process.h"
#include <assert.h>

int main(void){
	char sSecretWord[20] = {0};
	char* sWorking = 0; // NULL so that it cannot be used yet
	char* sHint = 0;
	char* sUnused = 0;
	char cGuess = '\0';
	char bGameRuning = 1; // used as a boolean
	int iNumLeft; // stores the number of letters the user still needs to guess
	int iRemainingLives = 7; // the number of lives left (one is lost whenever an incorrect guess is made)
	
	sUnused = malloc(27);
	assert(sUnused);
	strncpy(sUnused, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 27);
	getWord(sSecretWord,sizeof(sSecretWord));
	sWorking = createWorkingString(sWorking, sSecretWord);
	sHint = allocHint(strlen(sWorking)+1); // +1 so that it includes the NULL charichter
	// sceen needs to be cleared here so that the word which was inputted cannot be seen

	while (bGameRuning != 0){
		cGuess = getGuess(sUnused, sHint);	// does the printing for us
		//printf("You guessed %c\n", cGuess);

		sUnused = UpdateUnused(sUnused, cGuess);	
		//printf("sUnused is now %s", sUnused);
		
		if (UpdateHint(sWorking, sHint, cGuess) == 0) { // update the hint and deal with the lives condition
			iRemainingLives = iRemainingLives - 1;
			if (iRemainingLives == 0){
				printf("\nCongratulations to the player who chose the secret word. ");
				printf("The guessing player has run out of guesses\n");
				bGameRuning = 0; // do not loop again
			}
			else
				printf("You have %i guesses remaining\n",iRemainingLives );
		}

		iNumLeft = numLeftToGuess(sHint);

		if (iNumLeft == 0){ // check to see if all of the letters have been guessed
			printf("\nCongratulations to the guesser.You  have won!\n");
			printf("The secret word was %s\n", sSecretWord);
			bGameRuning = 0;
		}
				
	}	
	
	// clean up
	free(sUnused);
	sUnused = NULL;
	free(sHint);
	sHint = NULL;
	free(sWorking);
	sWorking = NULL; // good practice to allways make it NULL after a free. NO MATTER WHAT!
	return 0;
}
