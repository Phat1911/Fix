#include<stdio.h>
#include<math.h>
#include<string.h>
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
int main(){
	char n[20];
	printf("Nhap n = ");
	scanf("%s",&n);
	int bad = 0, m = 0;
	for (int i = 0; i < strlen(n); i++) {
	    if (n[i] == '.' || n[i] == '-') {
	        bad = 1;
	        break;
	    }
	    m = m * 10 + (n[i] - '0');
	}
	if(sohoanhao(m) && !bad){
		printf("%s la so hoan hao ",n);
	}else printf("%s khong la so hoan hao ",n);
	return 0;
}

