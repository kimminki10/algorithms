#include <cstdio>
int m, n; 
int arr[501][501];
int d[501][501];
bool check(int x, int y) {
    return (x >= 0 && y >=0 && x < m && y < n);
}
int dfs(int x, int y) {
    if (x == m-1 && y == n-1) {
        return 1;
    }

    if (d[x][y] != -1) {
        return d[x][y];
    }

    d[x][y] = 0;
    if (check(x, y-1) && arr[x][y-1] < arr[x][y]) { d[x][y] += dfs(x, y-1); }
    if (check(x, y+1) && arr[x][y+1] < arr[x][y]) { d[x][y] += dfs(x, y+1); }
    if (check(x-1, y) && arr[x-1][y] < arr[x][y]) { d[x][y] += dfs(x-1, y); }
    if (check(x+1, y) && arr[x+1][y] < arr[x][y]) { d[x][y] += dfs(x+1, y); }
    return d[x][y];
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = -1;
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d\n",dfs(0,0));
}
