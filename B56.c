#include<stdio.h>
#include<string.h>
void mang1chieu(int n, char a[][20]){
	int i;
	for( i=0;i<n;i++){
		scanf("%s",&a[i]);
	}
	for( i=0;i<n;i++){
		printf("%s ",a[i]);
	}printf("\n");
}
int sohoanhao(int n){
	int i,s;
	s=0;
	for(i=1;i<n;i++){
		if(n%i==0){
			s+=i;
		}
	}
	if(s==n){
		return 1;
	}else return 0;
}
void output(int n,char a[][20]){
	for(int i=0;i<n;i++){
	    int ok = 1, m = 0;
	    for (int j = 0; j < strlen(a[i]); j++) {
	        if (a[i][j] == '.' || a[i][j] == '-') {
	            ok = 0;
	            break;
	        }
	        m = m * 10 + (a[i][j] - '0');
	    }
		if(sohoanhao(m) && ok){
			printf("%s ",a[i]);
		}
	}
}
int main(){
	int n ;
	printf("Nhap n = ");
	scanf("%d",&n);
	char a[n][20];
	mang1chieu(n,a);
	output(n,a);
	return 0;

}

