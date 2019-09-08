#include <stdio.h>

long long result = -100000008;
long long int d[100005];
int arr[100005];


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    d[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] + d[i-1] > arr[i]) {
            d[i] = arr[i] + d[i-1];
        } else {
            d[i] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (result < d[i]) {
            result = d[i];
        }
    }
    printf("%lld\n", result);
}