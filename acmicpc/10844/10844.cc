#include <stdio.h>

long long d[102][10]; // d[n][m] m으로 끝나는 n자리 쉬운계단수
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i < 10; i++) {
        d[0][i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                d[i][j] = d[i-1][1];
            } else if (j == 9) {
                d[i][j] = d[i-1][8];
            } else {
                d[i][j] = d[i-1][j-1] + d[i-1][j+1] % 1000000000ll;
            }
        }
    }

    long long re = 0;
    for (int i = 0; i < 10; i++) {
        re = (re+ d[N-1][i]) % 1000000000ll;
    }
    printf("%lld\n", re);
}

/*
d 1 = 9 (1 - 9)
d 2 = 17(10 12
         21 23
         32 34
         43 45
         54 56
         65 67
         76 78
         87 89
         98 )
d 3 = 
*/