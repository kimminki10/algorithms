#include <stdio.h>

int d[1003]; // d[n] 2*n 일때 방법의 수
int main() {
    int n;
    scanf("%d", &n);

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }
    printf("%d\n", d[n]);
}