#include <stdio.h>

long long int d[92][2]; // d[n][m] 마지막 자리가 m인 n자리 이친수의 개수 
int main() {
    int N;
    scanf("%d", &N);

    d[1][1] = 1;
    d[2][0] = 1;
    for (int i = 2; i <= N; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    printf("%lld\n", d[N][1] + d[N][0]);
}