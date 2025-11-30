#include <stdio.h>
#include <string.h>
#include <math.h>

int getSign (char a[]) {
    int f = 0;
    for (int i = 0; i < strlen(a) && a[i] == '-'; i++) f++;
    return f;
}

int getDot (char a[]) {
    int pos = strlen(a) + 1;
    for (int i = 0; i < strlen(a); i++) if (a[i] == '.') {
        pos = i;
        break;
    }
    return pos;
}

int checkDot (char a[]) {
    for (int i = 0; i < strlen(a); i++) if (a[i] == '.') return 1;
    return 0;
}

void add (char a[], char b[]) {
    char ans[100000];
    int id = -1, nho = 0;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        if (a[i] == '.') {
            ans[++id] = '.';
            continue;
        }
        int tmp = (a[i] - '0') + (b[i] - '0') + nho;
        ans[++id] = (tmp % 10) + '0';
        nho = tmp / 10;
    }
    int flag = 0;
    if (nho) printf("%d", nho), flag = 1;
    for (int i = id; i >= 0; i--) {
        if (!flag && ans[i] == '0') continue;
        printf("%c", ans[i]);
        flag = 1;
    }
}

void procSub (char a[], char b[]) {
    char ans[100000];
    int id = -1, muon = 0;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        if (a[i] == '.') {
            ans[++id] = '.';
            continue;
        }
        int c = a[i] - '0', d = b[i] - '0';
        if (c < d + muon) c += 10;
        int tmp = c - d - muon;
        ans[++id] = tmp + '0';
        muon = c / 10;
    }
    int flag = 0;
    for (int i = id; i >= 0; i--) {
        if (ans[i] == '0' && !flag) continue;
        printf("%c", ans[i]);
        flag = 1;
    }
}

void sub (char a[], char b[]) {
    for (int i = 0; i < strlen(a); i++) {
        if ((a[i] - '0') < (b[i] - '0')) {
            printf("-");
            procSub(b, a);
            return;
        } else if ((a[i] - '0') > (b[i] - '0')) {
            procSub(a, b);
            return;
        }
    }
    printf("0");
}

int main () {
    char c[100000], d[100000];
    scanf("%s %s", &c, &d);
    if (!checkDot(c)) {
        c[strlen(c)] = '.';
        c[strlen(c)] = '0';
    }
    if (!checkDot(d)) {
        d[strlen(d)] = '.';
        d[strlen(d)] = '0';
    }
    int fa = getSign(c), fb = getSign(d);
    char a[100000], b[100000];
    int n = -1, m = -1, gdd = getDot(d) - fb, gdc = getDot(c) - fa;

    for (int i = 0; i < fmax(0, gdd - gdc); i++) a[++n] = '0';
    for (int i = 0; i < fmax(0, gdc - gdd); i++) b[++m] = '0';
    for (int i = 0; i < strlen(c); i++) if (c[i] != '-') a[++n] = c[i];
    for (int i = 0; i < strlen(d); i++) if (d[i] != '-') b[++m] = d[i];
    int n1 = n, m1 = m;
    for (int i = 0; i < fmax(0, m1 - n1); i++) a[++n] = '0';
    for (int i = 0; i < fmax(0, n1 - m1); i++) b[++m] = '0';
    // printf("%s %s\n", a, b);

    if (fa % 2 == 1) {
        if (fb % 2 == 1) { // - vs -
            printf("a + b = -"); add(a, b);
            printf("\n");
            printf("a - b = "); sub(b, a);
        } else { // - vs +
            printf("a + b = "); sub(b, a);
            printf("\n");
            printf("a - b = -"); add(a, b);
        }
    } else {
        if (fb % 2 == 1) { // + vs -
            printf("a + b = "); sub(a, b);
            printf("\n");
            printf("a - b = "); add(a, b);
        } else { // + vs +
            printf("a + b = "); add(a, b);
            printf("\n");
            printf("a - b = "); sub(a, b);
        }
    }
    return 0;
}

//---9.379 ----301.33
// 19 -20.001
// 19 -20

