#include <stdio.h>

inline int max(int a, int b) {
    return a>b?a:b;
}

inline int max(int a, int b, int c) {
    int re = 0;
    re = a>b?a:b;
    re = re>c?re:c;
    return re;
}

int d[100005][3]; // d[n][m] {m=0: 선택x, 1: 위에,2: 밑에}n번째 스티커 까지 선택 했을 때 스티커 점수의 최대 값 
int arr[100005][2]; //0 위에 1 아래

void testcase() {
    for (int i = 0; i < 100005; i++) {// 초기화
        arr[i][0] = arr[i][1] = 0;
        d[i][0] = d[i][1] = d[i][2] = 0;
    }
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i][0]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i][1]);
    }

    d[1][1] = arr[1][0];
    d[1][2] = arr[1][1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = max(d[i-1][1], d[i-1][2]);
        d[i][1] = max(d[i-1][0], d[i-1][2])+arr[i][0];
        d[i][2] = max(d[i-1][0], d[i-1][1])+arr[i][1];
    }

    printf("%d\n", max(d[n][0], d[n][1], d[n][2]));
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        testcase();
    }
}