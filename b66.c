#include<stdio.h>

void nhapmang(double A[], int n){
	int i;
	for ( i = 0; i < n ; i++){
		printf("Nhap A[%d] : ", i);
		scanf("%lf", &A[i]);
	}
}

void xoaam(double A[], int *n){
	int i, j = 0;
	for ( i = 0; i < *n; i++){
		if(A[i] >= 0.0) {
    		A[j]= A[i];
    		j++;
        }
    }
    *n = j;
}

void xuatmang(double A[], int n){
	int i;
	for(i = 0; i < n; i++){
	    double tmp = A[i];
	    if (tmp == 0.00) tmp = 0.0;
		printf("%.2lf ", tmp);
	}
}

int main(){
	int n;
	double A[10000];
	printf("So luong cac phan tu : ");
	scanf("%d", &n);

	nhapmang(A,n);
	printf("Mang A : ");
	xuatmang(A,n);

	xoaam(A, &n);
	printf("\n");
	printf("Mang A sau khi xoa cac phan tu am : ");
	xuatmang(A,n);
	return 0;
}
