#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;

void find_word(char *filename, char *word);

int main(int argc, char *argv[]) {
	if(argc==1){
		printf("wgrep: searchterm [file ...]");
		printf("\n");
		exit(1);
	}
	if (argc == 2) { 
		char buffer[250]; 
		while (fgets(buffer, 250, stdin)) { 
			if (strstr(buffer, argv[1]) != NULL) {
			       	printf("%s", buffer);
		       	}
	       	}
		exit(0);
       	}
	if(argc >= 3){ 
		//printf("%d", argc);
		for(int l=1; l<argc; l++){
			find_word(argv[l+1],argv[l]);
			l++;
		}
	}
	return 0;
}
void find_word(char *filename, char *word){
	       	char *line = NULL;
		size_t len = 0;
		FILE *fp = fopen(filename,"r");
		if(fp == NULL){
			//printf("%s",filename);
			printf("wgrep: cannot open file\n");
		    	exit(1);
		}
		else{
			while(getline(&line,&len,fp)!= -1){
				//printf("%s",line);
				if((strstr(line, word)) != NULL){
					printf("%s",line);
				}
			}
			fclose(fp);
		}
}
   
