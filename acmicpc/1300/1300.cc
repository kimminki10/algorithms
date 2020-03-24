/*
 * input: n <= 10^5 k <= 10 ^ 9
 * 
 * n = 4
 * 1 2 3 4
 * 2 4 6 8
 * 3 6 9 12
 * 4 8 12 16
 */
#include <cstdio>

inline int min(int a, int b) {
    return a < b? a:b;
}
bool isPossible(int n, int m, int k) {
    int num=0;
    for (int i = 1; i <= n; i++) {
        num += min(m / i, n);
    }
    return num < k;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int l = 1, r = k, m, ans = -1;
    while(l <= r) {
        m = (l + r) / 2;
        if (isPossible(n, m, k)) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }

    printf("%d\n", ans);
}
