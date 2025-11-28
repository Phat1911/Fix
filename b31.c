#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    printf("Nhap cac he so a, b, c (a khac 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == 0.0) {
        printf("He so a phai khac 0!\n");
        return 1;
    }
     int demNghiem = 0;
    double nghiem1, nghiem2, nghiem3, nghiem4;
     double delta = b * b - 4 * a * c;
    if(delta < 0.0) {
        demNghiem = 0;
        printf("Phuong trinh vo nghiem.\n");
    }
    else if(delta == 0.0) {
        double t = -b / (2 * a);
        if(t < 0.0) {
            demNghiem = 0;
            printf("Phuong trinh vo nghiem.\n");
        }
        else if(t == 0.0) {
            demNghiem = 1;
            nghiem1 = 0;
            printf("Phuong trinh co 1 nghiem: x = 0\n");
        }
        else {
            demNghiem = 2;
            nghiem1 = -sqrt(t);
            nghiem2 = sqrt(t);
            printf("Phuong trinh co 2 nghiem: x1 = %.2lf, x2 = %.2lf\n", nghiem1, nghiem2);
        }
    }
    else {
        double t1 = (-b - sqrt(delta)) / (2 * a);
        double t2 = (-b + sqrt(delta)) / (2 * a);
        int count = 0;
        if(t1 > 0.0) {
            nghiem1 = -sqrt(t1);
            nghiem2 = sqrt(t1);
            count += 2;
            printf("x1 = %.2lf, x2 = %.2lf\n", nghiem1, nghiem2);
        }
        else if(t1 == 0.0) {
            nghiem1 = 0;
            count += 1;
            printf("x = 0\n");
        }
        if(t2 > 0.0) {
            double x3 = -sqrt(t2);
            double x4 = sqrt(t2);

            if(t1 != t2) {
                if(t1 <= 0.0) {
                    printf("x3 = %.2lf, x4 = %.2lf\n", x3, x4);
                    count += 2;
                }
                else {

                    if(fabs(x3 - nghiem1) > 1e-9 && fabs(x3 - nghiem2) > 1e-9) {
                        printf("x3 = %.2lf\n", x3);
                        count++;
                    }
                    if(fabs(x4 - nghiem1) > 1e-9 && fabs(x4 - nghiem2) > 1e-9) {
                        printf("x4 = %.2lf\n", x4);
                        count++;
                    }
                }
            }
        }
        else if(t2 == 0.0) {
            if(t1 != 0.0) {
                printf("x = 0\n");
                count += 1;
            }
        }
         demNghiem = count;

        if(count == 0) {
            printf("Phuong trinh vo nghiem.\n");
        }
    }

    printf("So nghiem khac nhau: %d\n", demNghiem);

    return 0;
}

