#include <stdio.h>

int d[1003]; 
/* 
   d[n] = m 최대길이가 n일 때 최대값 m
*/
int arr[1003];
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    int di = 1;
    d[1] = arr[1];
    for (int i = 2; i <= N; i++) {
        if (d[di] < arr[i]) { // 큰게 나오면
            di += 1;
            d[di] = arr[i];
        } else if (d[di-1] < arr[i]) { // 이전꺼보다는 또 작으면
            d[di] = arr[i];
        }
    }
    
    printf("%d\n", di);
}