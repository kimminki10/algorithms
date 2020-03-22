#include <cstdio>
#include <cstring>

const int TS = 3000;

int nums[3];
int ta[TS][TS];
bool isSameColor(int x, int y, int a, int b) {
    int c = ta[x][y];
    for (int i = x; i < a; ++i) {
        for (int j = y; j < b; ++j) {
            if (ta[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int a, int b) {
    if (isSameColor(x, y, a, b)) {
       nums[1+ta[x][y]]++;
    } else {
        int dif = (a-x) / 3;
        int x1 = x + dif;
        int y1 = y + dif;
        int x2 = x + dif * 2;
        int y2 = y + dif * 2;
        solve(x, y, x1, y1);
        solve(x1, y, x2, y1);
        solve(x2, y, a, y1);
        solve(x, y1, x1, y2);
        solve(x1, y1, x2, y2);
        solve(x2, y1, a, y2);
        solve(x, y2, x1, b);
        solve(x1, y2, x2, b);
        solve(x2, y2, a, b);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &ta[i][j]);
        }
    }
    memset(nums, 0, sizeof(nums));

    solve(0, 0, n, n);
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", nums[i]);
    }
}

