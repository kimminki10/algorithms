#include <stdio.h>

int arr[10004];

bool isPossible(int N, int M, int m) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= m) {
            sum += arr[i];
        } else { sum += m; }
    }
    if (sum <= M) {
        return true;
    }
    return false;
}

int main() {
    int N, M, sum=0, l, r = 0, m; // upperbound
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > r) { r = arr[i]; }
    }
    scanf("%d", &M);

    if (sum <= M) {     // 예산이 충분하다면
        printf("%d\n", r);
        return 0;
    }

    while (l <= r) {
        m = (l+r)/2;
        if (isPossible(N, M, m)) {
            l = m+1;
        } else { r = m-1; }
    }

    printf("%d\n", r);
}