#include<stdio.h>
void enterSize_Element(int *arr,int *size){
	printf("Moi nhap vao do dai cua mang\n");
	scanf("%d",&(*size));
	printf("Moi nhap vao tung phan tu cua mang\n");
	for(int i=0;i<*size;i++){
		scanf("%d",&arr[i]);
	}
}
void printfEvenElement(int *arr,int *size){
	printf("Cac phan tu la so chan\n");
	for(int i=0;i<*size;i++){
		if(arr[i]%2==0){
			printf("%3d",arr[i]);
		}
	}
}
void printfElementPrime(int *arr,int *size){
	printf("Cac phan tu la so nguyen to\n");
	for(int i=0;i<*size;i++){
		int isPrime=1;
		if(arr[i]<2){
			isPrime=0;	
		}else{
		for(int j=2;j*j<=arr[i];j++){
			if(arr[i]%j==0){
				isPrime=0;
				break;
			}else{
				isPrime=1;
			}
		}
		}
		if(isPrime==1){
			printf("%3d",arr[i]);
		}
	}
}
void reverseArr(int *arr,int *size,int *reverse_arr){
	for(int i=0;i<*size;i++){
		reverse_arr[i]=arr[*size-i-1];
	}
	for(int i=0;i<*size;i++){
		arr[i]=reverse_arr[i];
	}
	printf("Mang sau khi dao nguoc\n");
 	for(int i=0;i<*size;i++){
		printf("%3d",arr[i]);
	}
}
void sortArr(int *arr,int *size){
	printf("Moi ban chon kieu sap xep");
	int selection;
	int temp;
	scanf("%d",&selection);
	fflush(stdin);
	switch(selection){
		case 1:
			for(int i=0;i<*size-1;i++){
				for(int j=0;j<*size-i-1;j++){
				if(arr[j]>arr[j+1]){
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
			break;
		case 2:
			for(int i=0;i<*size-1;i++){
				for(int j=0;j<*size-i-1;j++){
				if(arr[j]<arr[j+1]){
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
			break;
		default :
			break;	
	}
}
void search(int *arr,int *size,int *searchArr,int *is_Search_Arr,int *indexSearch){
	printf("Moi ban nhap vao phan tu muon tim\n");
	scanf("%d",searchArr);
	fflush(stdin);
	*indexSearch=0;
	*is_Search_Arr=-1;
	for(int i=0;i<*size;i++){
		if(arr[i]==*searchArr){
			*is_Search_Arr=1;
			*indexSearch=i;
			break;
		}
	}
}
int main(){
	int arr[100];
	int reverse_arr[100];
	int size;
	int select;
	int searchArr;
	int is_Search_Arr;
	int indexSearch;
	do{
		printf("\n");
		printf("\n");
		printf("----------MENU----------\n");
		printf("Lua chon 1:Nhap vao mang\n");
		printf("Lua chon 2:In ra cac phan tu la so chan\n");
		printf("Lua chon 3:In ra cac phan tu la so nguyen to\n");
		printf("Lua chon 4:Dao nguoc mang\n");
		printf("Lua chon 5:Sap xep mang theo lua chon\n1.Tang dan\n2.Giam dan\n");
		printf("Lua chon 6:Tim phan tu\n");
		printf("Lua chon 7:Thoat\n");
		printf("\n");
		printf("\n");
		printf("Moi nhap vao lua chon\n");
		scanf("%d",&select);
		fflush(stdin);
		switch(select){
			case 1:
				enterSize_Element(arr,&size);
				printf("Mang sau khi nhap\n");
				for(int i=0;i<size;i++){
					printf("%3d",arr[i]);
				}
				break;
			case 2:
				printfEvenElement(arr,&size);
				break;
			case 3:
				printfElementPrime(arr,&size);
				break;
			case 4:
				reverseArr(arr,&size,reverse_arr);
				break;
			case 5:
				sortArr(arr,&size);
				printf("Mang sau khi sap xep\n");
				for(int i=0;i<size;i++){
					printf("%d",arr[i]);
				}
				break;
			case 6:
				search(arr,&size,&searchArr,&is_Search_Arr,&indexSearch);
				if(is_Search_Arr==1){
					printf("Phan tu %d co trong mang o vi tri %d\n",searchArr,indexSearch);
				}else{
					printf("Khong tim thay phan tu trong mang\n");
				}
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
