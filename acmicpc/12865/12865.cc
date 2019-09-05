#include <stdio.h>

int d[102][100005];
int warr[102];
int varr[102];
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &warr[i], &varr[i]);
    }

    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= K; j++) {
            int a = d[i-1][j];
            int b;
            if (j - warr[i] >= 0){
                b = d[i-1][j - warr[i]]+varr[i];
            } else {
                b = d[i-1][j];
            }
            d[i][j] = a > b ? a : b;
        }
    }

    printf("%d\n", d[N][K]);
}