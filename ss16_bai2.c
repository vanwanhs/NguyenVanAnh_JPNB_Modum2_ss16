#include<stdio.h>
#include<string.h>
#include<ctype.h>

void menu(void){
    printf("\n--------Menu--------\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chu?i\n");
    printf("3. dem so luong chu cai trong chuoi và in ra\n");
    printf("4. dem so luong chu so trong chuoi và in ra\n");
    printf("5. dem so luong chu dac biet trong chuoi và in ra\n");
    printf("6. Thoat\n");
}

// nhap chuoi
/*void inPut(char *string, int size){
    printf("Moi ban nhap chuoi: ");
    fgets(string, size, stdin);
    string[strcspn(string, "\n")] = '\0';  // loai bo ki tu cuoi
}

// In chuoi
void outPut(char *string){
    printf("chuoi cua ban la: %s\n", string);
}

// Dem chu cai
void chuOfString(char *string){
    int chuCai = 0;
    printf("Cac chu cai co trong chuoi: ");
    for(int i = 0; i < strlen(string); i++){
        if(isalpha(string[i])){
            printf("%c ", *(string + i));
            chuCai++;
        }
    }
    printf("\nTong chu cai co trong chuoi: %d\n", chuCai);
}

// Dem chu so
void soOfString(char *string){
    int chuSo = 0;
    printf("Cac chu so co trong chuoi: ");
    for(int i = 0; i < strlen(string); i++){
        if(isdigit(string[i])){
            printf("%c ", *(string + i));
            chuSo++;
        }
    }
    printf("\nTong chu cai so?: %d\n", chuSo);
}

// dem ki tu dac biet
void dacBietOfString(char *string){
    int dacBiet = 0;
    printf("Các ký tu dac biet co trong chuoi: ");
    for(int i = 0; i < strlen(string); i++){
        if(!isalnum(string[i]) && !isspace(string[i])){
            printf("%c ", *(string + i));
            dacBiet++;
        }
    }
    printf("\nTong ki tu dac biet: %d\n", dacBiet);
}*/
void inPut(char *string, int size){
	printf("Moi ban nhap chuoi");
	fgets(string,size,stdin);
}
void outPut(char *string){
	printf("%s",string);
}
void chuOfString(char *string){
	int chuCai=0;
	printf("Cac phan tu co trong chuoi: ")
	for(int i=0;i<strlen(string);i++){
		if(isalpha(string[i])){
			chuCai++;
			printf("%d/t",*(string+i));
		}
	}
	printf("Tong chu cai co trong chuoi %d",chuCai);
}
int main(){
    char str[1000] = "";
    int choice;

    do {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        while(getchar() != '\n');  // xoa bo dem

        switch (choice){
            case 1:
                inPut(str, sizeof(str));
                break;
            case 2:
                outPut(str);
                break;
            case 3:
                chuOfString(str);
                break;
            case 4:
                soOfString(str);
                break;
            case 5:
                dacBietOfString(str);
                break;
            case 6:
                printf("Cam on ban da su dung!\n");
                break;
            default:
                printf("Khong hop le.\n");
        }
    } while (choice != 6);

    return 0;
}

