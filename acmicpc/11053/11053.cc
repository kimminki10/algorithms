#include <stdio.h>

int d[1003];
int arr[1001];
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (result < d[i]) result = d[i];
    }
    printf("%d\n", result);
}