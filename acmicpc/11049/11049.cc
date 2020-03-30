/*
 * 연산의 순서가 바뀌지 않아야한다.
 * 동적계획법
 */

#include <cstdio>

int dp[501][501]; // d[i][j] i 부터 j 까지 곱셈 할 때 연산횟수의 최솟값
int n; 
int r[501], c[501];

inline int min(int a, int b) {
    return a > b ? b: a;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &r[i], &c[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int x = 1; x + i <= n; x++) {
            int y = x + i;
            dp[x][y] = 0x3f3f3f3f;

            for (int m = x; m < y; m++) {
                dp[x][y] = min(dp[x][y], dp[x][m] + dp[m+1][y]+r[x]*c[m]*c[y]);
            }
        }
    }

    printf("%d\n", dp[1][n]);
}

