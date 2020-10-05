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
		int n_char;
		char c;
		while (fread(&n_char, 4, 1, fp)) { 
				fread(&c, 1, 1, fp);  
				for(int i=0;i<n_char;i++){
					printf("%c", c); 
				} 
			}
		fclose(fp);
	}
	return 0;
}
