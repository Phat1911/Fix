#include <stdio.h>
void NhapMaTran(double a[][101], int n) {
    printf("Nhap cac phan tu cua ma tran %dx%d:\n", n, n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}
void XuatMaTran(double a[][101], int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
}
double TimMaxHang(double a[][101], int n, int hang) {
    double max = a[hang][1];
    for(int j = 2; j <= n; j++) {
        if(a[hang][j] > max) {
            max = a[hang][j];
        }
    }
    return max;
}
int TimViTriMaxHang(double a[][101], int n, int hang) {
    double max = a[hang][1];
    int vi_tri_max = 1;
    for(int j = 2; j <= n; j++) {
        if(a[hang][j] > max) {
            max = a[hang][j];
            vi_tri_max = j;
        }
    }
    return vi_tri_max;
}
void DuaMaxLenCheoChinh(double a[][101], int n) {
    for(int i = 1; i <= n; i++) {
        int vi_tri_max = TimViTriMaxHang(a, n, i);
        double temp = a[i][i];
        a[i][i] = a[i][vi_tri_max];
        a[i][vi_tri_max] = temp;
    }
}
double TongMaxCacHang(double a[][101], int n) {
    double tong = 0;
    for(int i = 1; i <= n; i++) {
        double max = TimMaxHang(a, n, i);
        tong += max;
    }
    return tong;
}
int main() {
    int n;
    double a[101][101];
    printf("Nhap cap ma tran n: ");
    scanf("%d", &n);
    NhapMaTran(a, n);
    printf("\na. Ma tran A:\n");
    XuatMaTran(a, n);
    double tongMax = TongMaxCacHang(a, n);
    printf("\nb. Tong cac phan tu lon nhat cua tung hang: %lf\n", tongMax);
     DuaMaxLenCheoChinh(a, n);
    printf("Ma tran sau khi dua max len cheo chinh:\n");
    XuatMaTran(a, n);
    return 0;
}
