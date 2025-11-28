#include<stdio.h>

double sotrunggian1(double a, double b, double c){
	if((a<b && b < c )|| (c < b && b < a)) return b;
	if( (b < a && a < c )|| (c < a && a < b)) return a;
	return c;
}

double sotrunggian2(double a, double b, double c){
	return ((a<b && b < c) || (c < b && b < a)) ?  b : (( b < a && a < c )|| (c < a && a < b)) ?  a : c;

}

int main(){
	double a,b,c,m,n;
	printf("Nhap 3 so :");
	scanf("%lf %lf %lf", &a, &b, &c);
	m = sotrunggian1(a,b,c);
    n = sotrunggian2(a,b,c);
    printf("so trung gian 1 la : %lf\n", m);
    printf("so trung gian 2 la : %lf", n);

	return 0;
}
