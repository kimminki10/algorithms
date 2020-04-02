#include <cstdio>

int n, m;
int arr[2001];
int d[2001][2001] = {0,};
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        d[i][i] = 1;  
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            d[i][i+1] = 1;
        }  
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; j <= n-i; j++) {
            if (arr[j] == arr[j+i] && d[j+1][j+i-1]) {
                d[j][j+i] = 1;
            }
        }
    }
    int s, e;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s][e]);
    }
}

