#include <stdio.h>
#include <string.h>

void xuat(char a[][20], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
}

void maxNguyenLe(char a[][20], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1, m = 0;
        for (int j = 0; j < strlen(a[i]); j++) {
            if (a[i][j] == '-' || a[i][j] == '.') {
                ok = 0;
                break;
            }
            m = (m * 10) + (a[i][j] - '0');
        }
        if (ok && m % 2 == 1) {
            if (ans < m) ans = m;
        }
    }
    printf(ans == 0 ? "Khong co gia tri nguyen duong le trong mang" : "%d", ans);
}

int main () {
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    char a[n][20];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    xuat(a, n);
    maxNguyenLe(a, n);
    return 0;
}
