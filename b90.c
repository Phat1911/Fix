#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *ptr1, const void *ptr2){
    double *x = (double*)ptr1;
    double *y = (double*)ptr2;
    if (*x > *y) return 1;
    if (*x < *y) return -1;
    return 0;
}

int bs (double a[], long long n, double x) {
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) return 1;
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int kTraTapCon (double cha[], double con[], long long n, long long m) {
    for (int i = 0; i < m; i++) {
        if (!bs(cha, n, con[i])) return 0;
    }
    return 1;
}

int main () {
    long long n, m;
    printf("Moi nhap so phan tu tap hop A: ");
    scanf("%lld", &n);
    printf("A = ");
    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("Moi nhap so phan tu tap hop B: ");
    scanf("%lld", &m);
    printf("B = ");
    double b[m];
    for (int i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }
    int f = 0;
    printf("Hop cua A va B = ");
    qsort(a, n, sizeof(double), cmp);
    qsort(b, m, sizeof(double), cmp);
    for (int i = 0; i < n; i++) printf("%lf ", a[i]);
    for (int i = 0; i < m; i++) {
        if (!bs(a, n, b[i])) printf("%lf ", b[i]), f = 1;
    }
    if (!f) printf("Rong");
    f = 0;
    printf("\n");
    printf("Giao cua A va B = ");
    for (int i = 0; i < m; i++) {
        if (bs(a, n, b[i])) printf("%lf ", b[i]), f = 1;
    }
    if (!f) printf("Rong");
    f = 0;
    printf("\n");
    printf("A hieu B = ");
    for (int i = 0; i < n; i++) {
        if (!bs(b, m, a[i])) printf("%lf ", a[i]), f = 1;
    }
    if (!f) printf("Rong");
    f = 0;
    printf("\n");
    printf("B hieu A = ");
    for (int i = 0; i < m; i++) {
        if (!bs(a, n, b[i])) printf("%lf ", b[i]), f = 1;
    }
    if (!f) printf("Rong");

    printf("\nMoi nhap so phan tu cua tap hop cha(C): ");
    scanf("%lld", &n);
    printf("C = ");
    double cha[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cha[i]);
    }
    printf("Moi nhap so phan tu tap hop con(D): ");
    scanf("%lld", &m);
    printf("D = ");
    double con[m];
    for (int i = 0; i < m; i++) {
        scanf("%lf", &con[i]);
    }
    printf(kTraTapCon(cha, con, n, m) ? "D la tap con cua tap hop C\n" : "D khong phai tap con cua C\n");
}
// 3
// -1 5.100 2.3
// 3
// -1.001 4.2 2
