#ifndef PROCESS_H
#define PROCESS_H

int numLeftToGuess(char* s);
char UpdateHint(char* sWorkingString, char* sHint, char cGuess);
char* UpdateUnused(char* sOld, const char ccGuess);

#endif
