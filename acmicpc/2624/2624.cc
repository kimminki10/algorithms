#include <stdio.h>

int p[102];
int n[102];

int d[10004][102]; // 목표지폐금액 동전종류 교환방법수

// void printD(int T, int k) {
//     for (int j = 0; j <= k; j++){
//         for (int i = 0; i <= T; i++) {
//             printf("%d%c", d[i][j], " \n"[i == T]);
//         }
//     }
//     printf("--------\n");
// }
int main() {
    int T;
    scanf("%d", &T);
    
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p[i], &n[i]);
    }

    d[0][0] = 1;
    for (int j = 1; j <= k; j++){
        for (int i = 0; i <= T; i++) {
            if (d[i][j-1] != 0) {
                for (int l = 0; l <= n[j-1]; l++) {
                    if (i+p[j-1]*l <= T)
                        d[i+p[j-1]*l][j] += d[i][j-1];
                }
                //printD(T, k);
            }
        }
    }

    printf("%d\n", d[T][k]);
}