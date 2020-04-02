#include <cstdio>


inline int min(int a, int b) {
    return a > b ? b : a;
}

void testcase() {
    int k; scanf("%d", &k);
    int arr[501] = {0, };
    int d[501][501]= {0, };
    int sum[501]= {0, };
    for (int i = 1; i <= k; i++) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i-1] + arr[i];
    }

    for (int i = 1; i < k; i++) {
        for (int x = 1; x + i <= k; x++) {
            int y = x + i;
            d[x][y] = 0x3f3f3f3f;

            for (int m = x; m < y; m++) {
                d[x][y] = min(d[x][y], d[x][m] + d[m+1][y] + sum[y]-sum[x-1]);
            }
        }
    }
    printf("%d\n", d[1][k]);
}

int main() {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        testcase();
    }
}

