
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
double TimMinHang(double a[][101], int n, int hang) {
    double min = a[hang][1];
    for(int j = 2; j <= n; j++) {
        if(a[hang][j] < min) {
            min = a[hang][j];
        }
    }
    return min;
}
int TimViTriMinHang(double a[][101], int n, int hang) {
    double min = a[hang][1];
    int vi_tri_min = 1;
    for(int j = 2; j <= n; j++) {
        if(a[hang][j] < min) {
            min = a[hang][j];
            vi_tri_min = j;
        }
    }
    return vi_tri_min;
}
void DuaMinLenCheoPhu(double a[][101], int n) {
    for(int i = 1; i <= n; i++) {
        int vi_tri_min = TimViTriMinHang(a, n, i);
        double temp = a[i][n+1-i];
        a[i][n+1-i] = a[i][vi_tri_min];
        a[i][vi_tri_min] = temp;
    }
}
double TongMinCacHang(double a[][101], int n) {
    double tong = 0.0;
    for(int i = 1; i <= n; i++) {
        double min = TimMinHang(a, n, i);
        tong += min;
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
     double tongMin = TongMinCacHang(a, n);
    printf("\nb. Tong cac phan tu be nhat cua tung hang: %.2lf\n", tongMin);
     DuaMinLenCheoPhu(a, n);
    printf("Ma tran sau khi dua min len cheo phu:\n");
    XuatMaTran(a, n);
    return 0;
}
