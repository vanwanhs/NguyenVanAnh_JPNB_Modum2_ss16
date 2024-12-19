#include<stdio.h>
#include<ctype.h>
#include<string.h>
void enterString(char *string,int *len){
	printf("Moi ban nhap vao mot chuoi bat ki\n");
	fgets(string,100,stdin);
	string[strcspn(string,"\n")]='\0';
	*len=strlen(string);
}
void printfReverseString(char *string,char *reverseString,int *len){
	for(int i=0;string[i]!='\0';i++){
		*(reverseString+i)=*(string+*len-i-1);
	}
	*(reverseString+*len)='\0';
}
void countWords(char *string,int *countWord,int *len){
	int isSpace=0;
	for(int i=0;*(string +i)!='\0';i++){
		if(isspace( *(string+i) ) ){
			isSpace=1;
		}else{
			isSpace=0;
		}
		if(isSpace==1){
			(*countWord)++;
			if(isspace( *(string+i+1) ) ){
				(*countWord)--;
			}
		}
	}
}
void compare(char *string,char *newstring,int *compares){
	printf("Moi ban nhap vao chuoi moi\n");
	fgets(newstring,100,stdin);
	newstring[strcspn(newstring,"\n")]='\0';
	fflush(stdin);
	*compares=strcmp(string,newstring);
}
void capital(char *string,int *capitals){
	for(int i=0;string[i]!='\0';i++){
		*capitals=isupper(string[i]);
		if(*capitals!=0){
			*(string+i)=toupper(*(string+i));
		}
		
	}
}
void appends(char *string,char *newstring,char *appendsString){
	printf("Moi ban nhap vao chuoi moi\n");
	fgets(newstring,100,stdin);
	newstring[strcspn(newstring, "\n")] = '\0';
	strcpy(appendsString, string);
    strcat(newstring,appendsString);;
}

int main(){
	char string[100];
	char reverseString[100];
	char newstring[100];
	char appendsString[100];
	int len=0;
	int select;
	int countWord=0;
	int compares;
	int capitals;
	do{
		printf("\n");
		printf("\n");
		printf("----------MENU----------\n");
		printf("Lua chon 1:Nhap vao chuoi\n");
		printf("Lua chon 2:In ra chuoi dao nguoc\n");
		printf("Lua chon 3:Dem so luong tu trong chuoi\n");
		printf("Lua chon 4:Nhap vao mot chuoi moi va so sanh hai chuoi\n");
		printf("Lua chon 5:In hoa tat ca cac chu cai trong chuoi\n");
		printf("Lua chon 6:Them mot chuoi vao chuoi ban dau\n");
		printf("Lua chon 7:Thoat\n");
		printf("\n");
		printf("\n");
		printf("Moi nhap vao lua chon\n");
		scanf("%d",&select);
		fflush(stdin);
		switch(select){
			case 1:
				enterString(string,&len); 
				printf("Chuoi sau khi nhap la: %s\n",string);
				break;
			case 2:
				printfReverseString(string,reverseString,&len);
				printf("Chuoi sau khi dao nguoc la: %s",reverseString);
				break;
			case 3:
				countWords(string,&countWord,&len);
				printf("So luong tu trong chuoi %d",countWord);
				break;
			case 4:
				compare(string,newstring,&compares);
				if(compares==0){
					printf("Hai chuoi bang nhau.\n");
				}else if(compares<0){
					printf("Chuoi string ngan hon chuoi newstring");
				}else{
					printf("Chuoi string dai hon chuoi newstring");
				}
				break;
			case 5:
				capital(string,&capitals);
				printf("%s",string);
				break;
			case 6:
				appends(string,newstring,appendsString);
				printf("%s",appendsString);
				break;
			case 7:
				printf("STOP ALL");
				break;
			default :
				printf("Moi ban nhap lai lua chon");
				break;			
		}
	}while(select!=7);
	return 0;
}
