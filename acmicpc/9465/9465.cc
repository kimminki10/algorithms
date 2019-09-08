#include <stdio.h>

int d[100005][2];
int arr[100005][2];

void testcase() {
    for (int i = 0; i < 100005; i++) {// 초기화
        arr[i][0] = arr[i][1] = 0;
    }
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i][1]);
    }

    

}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        testcase();
    }
}