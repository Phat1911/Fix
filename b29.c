#include <stdio.h>
#include <string.h>

int main () {
    char n[1000001];
    scanf("%s", n);
    int st = 0;
    if (n[0] == '-') {
        st = 1;
        printf("-");
    }
    for (int i = strlen(n); i >= st; i--) {
        printf("%c", n[i]);
    }
    return 0;
}

