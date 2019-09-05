#include <stdio.h>
#include <algorithm>
using namespace std;
int d[502][502]; 
// d[n][m] 마지막에 m번째 것을 선택 했을 때 n번째 줄까지 합의 최대 값

void updateD(int i, int j, int v) {
    if (d[i][j] < v) {
        d[i][j] = v;
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[502][502] = {0,};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    d[0][0] = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int l = arr[i+1][j]+d[i][j];
            int r = arr[i+1][j+1]+d[i][j];
            updateD(i+1,j, l);
            updateD(i+1,j+1, r);
        }
    }
    int maxv = 0;
    for (int i = 0; i < n; i++) {
        if (maxv < d[n-1][i]) {
            maxv = d[n-1][i];
        }
    }
    printf("%d\n", maxv);
}