#include <stdio.h>
#include <algorithm>

using namespace std;

int m[102];
int c[102];
int d[102][10004]; // d[n][m] n번째 앱까지 m: 앱 비활성화 비용의 합 
int ff(int i, int cost) {
    if (i < 0) return 0;

    int &result = d[i][cost];
    if (result != -1) return result;
    result = ff(i-1, cost);
    if (cost - c[i] >= 0) {
        result = max(result, ff(i-1,cost-c[i])+m[i]);
    }
    return result;
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int l = 0, r = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &m[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
        r += c[i];
    }
    for (int i = 0; i < 102; i++) {
        for(int j = 0; j < 10004; j++) {
            d[i][j] = -1;
        }
    }
    while(l<=r) {
        int mid = (l+r)/2;
        if (ff(N-1, mid) >= M) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    printf("%d\n", l);
}