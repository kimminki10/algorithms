#include <cstdio>

int main() {
    int a, b;
    int re;
    while ( (re = scanf("%d %d", &a, &b) == 2) ) {
        if (a==0 && b==0) {
            return 0;
        }
        if (a % b == 0) {
            printf("multiple\n");
        } else if (b%a==0) {
            printf("factor\n");
        } else {
            printf("neither\n");
        }
    }
}