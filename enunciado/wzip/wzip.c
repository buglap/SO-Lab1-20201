#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void make_zip(char *filename);
char *read_file(char *filename){
	char *buffer = NULL;
	int string_size, read_size;
	FILE *fp = fopen(filename, "r");
	if(fp==NULL){
		printf("wzip: cannot open file\n");
		exit(1);
	}
	if (fp){
	       	fseek(fp, 0, SEEK_END);
		string_size = ftell(fp);
		rewind(fp);
		buffer = (char*) malloc(sizeof(char) * (string_size + 1) );
		read_size = fread(buffer, sizeof(char), string_size, fp);
		buffer[string_size] = '\0';
		if (string_size != read_size){
			free(buffer);
			buffer = NULL;
		}
		fclose(fp);
	}
	return(buffer);
}
char *remove_spaces(char *str){
	  char *out = str, *put = str;
	  for(; *str != '\0'; ++str){
		  if(*str != ' ')
			  *put++ = *str;
	  }
	  *put = '\0';
	  return out;
}
int main(int argc,char *argv[]){
	char *str;
	char *string;
	if(argc==1){
		printf("wzip: file1 [file2 ...]");
		printf("\n");
		exit(1);
	}
	if(argc >= 2){ 
		if(argc ==2){
			str = read_file(argv[1]);
			make_zip(str);
			return 0;
		}
		string = read_file(argv[1]);
		char *str2 =  read_file(argv[2]);
		if(argc == 3){
			str = (char*)malloc((1+ strlen(string) + strlen(str2)));
			strcpy(str, string);
			strcat(str, str2);
			make_zip(str);
			return 0;
		}else if(argc == 4){
			char *str3 = read_file(argv[3]);
			str = (char*)malloc((1+ strlen(string) +strlen(str3)+ strlen(str2)));
			strcpy(str, string);
			strcat(str,str2);
			strcat(str, str3);
			make_zip(str);
			return 0;
		}
	}
	return 0;
}
void make_zip(char *string){
	int len = strlen(string);
	int count = 1;
	char *str = remove_spaces(string);
	if(str){
		 for(int i = 0; i < len; i++){
			if(str[i]==str[i+1]){
				count++;
			}
			else if(str[i]!=str[i+1]){
				fwrite(&count, 1, sizeof(count), stdout);
				fwrite(&str[i], 1, 1, stdout);
				count = 1;
			}
		 }
	}
}


