#include <cstdio>

int d[501][2]; // 0 -> 2의개수 1 -> 5의 개수

int aa(int n, int mod) {
    int i = 0;
    while (n % mod == 0) { i++; n = n/mod;}
    return i;
}

inline int minmin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        d[i][0] = aa(i, 2) + d[i-1][0];
        d[i][1] = aa(i, 5) + d[i-1][1];
    }
    printf("%d\n" , minmin(d[n][0], d[n][1]));
}

