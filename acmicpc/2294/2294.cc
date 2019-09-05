#include <stdio.h>
#include <string.h>

const int inf = 0x3f3f3f3f;
int d[10004];
int arr[102];
int main() {
    int n, k, tmp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    for (int j = 0; j <= k; j++){
        for (int i = 0; i < n; i++) {
            if (j+arr[i] < k && d[j+arr[i]] > d[j] + 1)
                d[j+arr[i]] = d[j] + 1;
        }
    }

    if (d[k] < inf)
        printf("%d\n", d[k]);
    else
        printf("-1\n");
}