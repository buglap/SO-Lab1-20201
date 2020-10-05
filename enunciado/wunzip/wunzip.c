#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	if(argc==1){
		printf("wunzip: file1 [file2 ...]");
		printf("\n");
		exit(1);
       	}
	for(int l=1; l<argc; l++){
		FILE* fp = fopen(argv[l], "r");
		if(fp==NULL){
			printf("wunzip: cannot open file\n");
			exit(1);
		}
		//int counter = 1;
		char ca = fgetc(fp);
		char c;
		while(ca != EOF){
			c = fgetc(fp);
			c = fgetc(fp);
			c = fgetc(fp); 
			c = fgetc(fp); 
		       	for (int i = 0; i < ca; i++){                                                                                                                                                   printf("%c", c);                                                                                                                                                }
			ca =fgetc(fp);			
		}
		fclose(fp);
	}
	return 0;
}
