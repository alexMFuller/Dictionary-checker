#include "spell.h"

int main(void) {
  char** dict;
	
	char dictPath[100];
	char inPath[100];
	FILE* in_file;
	do{
		errno=0;
		printf("Enter Dictionary path: ");
		scanf("%s",dictPath);
		in_file = fopen(dictPath, "r");
	}while(errno!=0);

	fclose(in_file);

	do{
		errno=0;
		printf("Enter input path: ");
		scanf("%s",inPath);
		in_file = fopen(inPath, "r");
	}while(errno!=0);
	
	int dictSize = parseDict(dictPath,&dict);
	
	char str[100];
	
	int isValid = 0;
	int lnNum= 0;
	char *token;
	char* s = " \n";
	while(fgets(str,100, in_file)!=NULL){
		/* get the first token */
		lnNum++;
  	token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      isValid = validWord(token,dict);
			
			if(!isValid){
				bad_word(token, lnNum, stderr);
			}
			//printf( "%s\n", token );
      token = strtok(NULL, s);
   }
		

	}

	//printf("here\n");
	//printf("%d\n",size);
	
}
