#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[200005];
bool isPossible(int N, int C, int m) {
    int tmp = arr[0];
    int num = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] - tmp >= m) {
            num += 1;
            tmp = arr[i];
        }
    }
    if (num >= C) { return true; }
    return false;
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);
    
    int l = 1, r = arr[N-1]-arr[0], ans = -1, m;
    while(l <= r) {
        m = (l+r)/2;
        if (isPossible(N, C, m)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    printf("%d\n", ans);
}