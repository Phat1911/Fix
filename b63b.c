#include<stdio.h>
#include<math.h>
#include<string.h>
int nt(long long n){
    int m = sqrt(n);
    return m * m == n;
}

int main(){
    int n; printf("Nhap so luong cho mang: ", n);
    scanf("%d", &n);

    char a[n][20];
    for (int i = 0; i < n; i++){
        scanf("%s", &a[i]);
    }

    int sum = 0;

    printf("Cac so chinh phuong trong mang:\n");
    int cnt = 0;
    for (int i = 0; i < n; i++){
        long long m = 0, ok = 1;
        for (int j = 0; j < strlen(a[i]); j++) {
            if (a[i][j] == '.' || a[i][j] == '-') {
                ok = 0;
                break;
            }
            m = m * 10 + (a[i][j] - '0');
        }
        if (nt(m) && ok){
            printf("%s ", a[i]);
            sum += m;
        }
    }

    printf("\nTong cac so chinh phuong da nhap la: %d", sum);

    return 0;
}
