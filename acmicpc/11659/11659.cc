#include <stdio.h>

int N, M;
int arr[100005];
int sum[100005];
int main() {
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i-1] + arr[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[b] - sum[a-1]);
    }
}