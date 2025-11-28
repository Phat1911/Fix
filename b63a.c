#include<stdio.h>

void nhap(double a[], int n){
    for(int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
}

void in(double a[], int n){
    for(int i = 0; i < n; i++){
        printf("%lf ", a[i]);
    }
}

int main(){
    int n; scanf("%d", &n);
    double a[n];
    nhap(a,n);
    in(a,n);
    return 0;
}
