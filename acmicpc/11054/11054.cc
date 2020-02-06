#include <cstdio>

int arr[1003];
int d[1003][2]; // 0: inc, 1: dec
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ",&arr[i]);
    }

    for (int i = 0; i < n; i++){
        // 가장긴 증가하는 부분수열
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && d[i][0] < d[j][0] + 1) {
                d[i][0] = d[j][0] + 1;
            }
        }
        // 뒤부터 증가하는 부분수열
        for (int j = 0; j < i; j++) {
            if (arr[n-i-1] > arr[n-j-1] && d[n-i-1][1] < d[n-j-1][1] + 1) {
                d[n-i-1][1] = d[n-j-1][1] + 1;
            }
        }
    }

    int maxmax = 0;
    for (int i = 0 ; i < n; i++) {
        if (maxmax < d[i][0]+ d[i][1]) {
            maxmax = d[i][0] + d[i][1];
        }
    }
    printf("%d\n", maxmax+1);
 }