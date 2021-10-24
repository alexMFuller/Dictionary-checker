#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>
#include <ctype.h>

#ifndef spellLib_h
#define spellLib_h

int bad_word(char* word, int line, FILE* out);
int wordSearch(char* word, char** dict);
int parseDict(char* pathname, char*** output);
int validWord(char* word, char** dict);
int myWordSearch(char* word, char** dict);

#endif