#include <stdio.h>

void b(int n, double a[][101]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", a[j][i]);
        }
        printf("\n");
    }
}

void a() {
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    double a[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    printf("A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("A^(-1):\n");
    b(n, a);
}

int main() {
    a();
    return 0;
}
