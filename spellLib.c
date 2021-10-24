#include "spellLib.h"

int parseDict(char* pathname, char*** output){
	int numWords = 1;
	/*
	You must implement a function int parseDict(char* pathname, char*** output) which opens the given file, counts how many dictionary entries are in the file, creates an array large enough to hold all the words, then reads the file a second time to load the words into the dictionary. It writes the address of the dictionary array into output and returns the number of elements in the dictionary.
	*/
	FILE* in_file = fopen(pathname, "r"); // read only 

	char str[100];
	
	while(fgets(str,100, in_file)!=NULL){
            numWords++;
    }
	
	char **wordArray = malloc(numWords*sizeof(char*));
	
	rewind(in_file);

	int i = 0;
	//printf("%d\n",numWords);

	for(i=0;i<numWords;i++){
			fgets(str,100, in_file);
			//allocate size of word[i]
			wordArray[i] = malloc(100*sizeof(char));
			char* formStr = strtok(str, " \n");
			strncpy(wordArray[i],formStr,100);
			//printf("%s", wordArray[i]);
		}
		wordArray[numWords] = "\0";

	*output = wordArray;
	
	return numWords;
}

int bad_word(char* word, int line, FILE* out){
	int t = 1;
	/*
	prints the error message "Unknown word word found in line line of the input file" to the specified stream. The function returns 1 if the message is printed successfully, 0 if there is a problem
	*/
	
	fprintf(out, "Unknown word '%s' found in line '%d' of the input file\n", word, line);

	if(errno!=0){
		t = 0;
		return t;
	}
	return t;

}

int wordSearch(char* word, char** dict){
		/*
	Implement and use a function int wordSearch(char* word, char** dict), which returns 1 if the word word is found in the array of strings, dict. The function returns 0 if the word is not found or if the dictionary array is not valid.
	*/
	int t = 0;
	int place = 0;
	//int size = sizeof(dict) / sizeof(dict[0]);
	//printf("%d\n",size);

	while(dict[place]!=NULL){
		//printf("%s = %s\n",word,dict[place]);
		if (!strncasecmp(word,dict[place],strlen(word))){
			t=1;
			return t;
		}
		else{
			place++;
		}
		
	}
	return t;
}

int validWord(char* word, char** dict){
	int t = 0;
	int foundWord = 0;
	char* temp = malloc(100*sizeof(char));
		
		for(int i = 0;i<strlen(word);i++){
			
			if(isalpha(word[i])){
				temp = strncat(temp, &word[i], 1);
				//printf("%s\n",temp);
			}
			
		}
		foundWord = (wordSearch(temp, dict));
			if (!foundWord){
				t = 0;
				//printf("here");
			}
			else if(foundWord){
				t = 1;
				//printf("found here");
			}

	//printf("Word:%lu vs Temp:%lu\n",sizeof word,sizeof temp);
		

	
	return t;
}

