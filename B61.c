#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ktraNto (int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int main () {
    int n;
    scanf("%d", &n);
    char a[n][20];
    for (int i = 0; i < n; i++) {
        scanf("%s", &a[i]);
    }
    int sum = 0;
    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; i++) {
        int flag = 0, num = 0;
        for (int j = 0; j < strlen(a[i]); j++) {
            if (a[i][j] == '.') {
                flag = 1;
                break;
            }
            num = num * 10 + (a[i][j] - '0');
        }
        if (flag) continue;
        if (ktraNto(num)) {
            sum += num;
            printf("%d ", num);
        }
    }
    printf("\nTong cac so nguyen to: %d", sum);
    return 0;
}
