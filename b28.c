#include <stdio.h>
#include <stdlib.h>

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int UCLN (int a[], int len) {
    int g = gcd(a[1], a[2]);
    for (int i = 3; i <= len; i++) g = gcd(g, a[i]);
    return abs(g);
}

int BCNN (int a[], int len) {
    int ans = 1;
    for (int i = 1; i <= len; i++) ans *= a[i];
    return abs(ans) / UCLN(a, len);
}

int main () {
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    int a[n+1];
    printf("Nhap cac phan tu cua mang a: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    printf("UCLN: %d \nBCNN: %d", UCLN(a, n), BCNN(a, n));
    return 0;
}
