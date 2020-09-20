#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
void file_printer(char *filename);

int main(int argc, char *argv[]) {
	if(argc!=2){
		exit(1);
	}
	while( *(++argv) ){
	    file_printer(*argv);
	}		
	return 0;
}


void file_printer(char *filename){
	char buff[255];
	FILE *fp = fopen(filename,"r");
	if(fp == NULL){
		printf("archivo vacio");
	}
	else{
		while(fgets(buff,255,fp) != NULL){
			printf("%s",buff);
		}
		fclose(fp);
	}
	exit(1);
}
