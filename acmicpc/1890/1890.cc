#include <stdio.h>

long long d[102][102];
int bo[102][102];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &bo[i][j]);
        }
    }

    d[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (d[i][j] == 0 || (i == N-1 && j == N-1)) { 
                continue; // 연결 되어있지 않거나 종착점이면
            }
            int c = bo[i][j];
            if (i+c < N) { d[i+c][j] += d[i][j]; }
            if (j+c < N) { d[i][j+c] += d[i][j]; }
        }
    }

    printf("%lld\n", d[N-1][N-1]);
}