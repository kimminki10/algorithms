#include <stdio.h>

int d[10004];
int arr[10004];
int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    d[0]=1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++){
            if (j+arr[i] <= k) 
                d[j+arr[i]] += d[j];
        }
    }

    printf("%d\n", d[k]);
}