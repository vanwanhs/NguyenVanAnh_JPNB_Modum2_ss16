#include<stdio.h>
#include<string.h>
// menu
void menu(void){
	printf("--------Menu--------\n");
	printf("1. nhap do dai va tung phan tu co trong mang\n");
	printf("2. Hien thi cac phan tu co trong mang\n");
	printf("3. Tinh do dai cua mang\n");
	printf("4.Tinh tong cac phan tu co trong mang\n");
	printf("5. Hien thi phan tu lon nhat\n");
	printf("6. Thoats\n");
}
// nhap do dai va tung phan tu co trong mang
void input(int *array, int *length){
	printf("Moi ban nhap do dai cua mang: ");
	scanf("%d", length);
	if(*length<0||*length>100){
		printf("Moi ban nhap lai do dai cua mang\n");
		return;
	} else {
		for(int i=0; i<*length;i++){
			printf("array[%d]= ",i);
			scanf("%d",&array[i]);
		}
	}
}
// in mang
void output(int *array, int *length){
	if(*length>100||*length<=0){
		return;
	}
	printf("Phan tu co trong mang\n");
	for(int i=0;i<*length;i++){
		printf("array[%d]= %d",i,*(array+i));
		printf("\n");
	}
}
// tinh do dai cua mang
// tinh tong cac phan tu co trong mang
int sumArray(int *array, int *length){
	int sum=0;
	for(int i=0;i<*length;i++){
		sum += *(array+i);
	}
	return sum;
}
// tim phan tu lon nhat trong mang
int maxElement(int *array, int *length){
	int max=array[0];
	for(int i=0;i<*length;i++){
		if(*(array+i)>max){
			max=array[i];
		}
	}
	return max;
}
int main(){
	int array[100];
	int length=0;
	int choice;
	do{
		menu();
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			
			case 1:
				input(array,&length);
				break;
			case 2:
				output(array,&length);
				break;
			case 3:
				printf("Do dai cua mang %d\n",length);
				break;
			case 4:
				printf("Tong cua mang la: %d\n",sumArray(array,&length));
				break;
			case 5:
				if(length<0||length>100){
					break;
				}
				printf("Phan tu lon nhat co trong mang la : %d\n",maxElement(array,&length));
				break;
			case 6:
				printf("Cam on ban da su dung ung dung\n");
				break;
			default :
				printf ("Moi ban nhap lai\n");
		}
	}while (choice!=6);


	return 0;
}

