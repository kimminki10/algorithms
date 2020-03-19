#include <cstdio>

int main() {
    int n, m, k;
    int A[101][101], B[101][101], C[101][101];
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int l = 0; l < k; ++l) {
            for (int j = 0; j < m; ++j) {
                C[i][l] += A[i][j] * B[j][l];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

