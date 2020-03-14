#include <cstdio>
#include <cstring>

const int TS = 128;

void printta(int ta[TS][TS], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d%c", ta[i][j], " \n"[j == n-1]);
        }
    }
}

int white = 0;
int blue = 0;

bool isSameColor(int x, int y, int a, int b, int ta[TS][TS], int color) {
    for (int i = x; i < a; ++i) {
        for (int j = y; j < b; ++j) {
            if (ta[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

bool isWhite(int x, int y, int a, int b, int ta[TS][TS]) {
    return isSameColor(x, y, a, b, ta, 0);
}

bool isBlue(int x, int y, int a, int b, int ta[TS][TS]) {
    return isSameColor(x, y, a, b, ta, 1);
}

void solve(int x, int y, int a, int b, int ta[TS][TS]) {
    if (isWhite(x, y, a, b, ta)) {
        ++white;
    } else if (isBlue(x, y, a, b, ta)) {
        ++blue;
    } else {
        int mx = (a+x)/2;
        int my = (b+y)/2;
        solve(x, y, mx, my, ta);
        solve(mx, my, a, b, ta);
        solve(mx, y, a, my, ta);
        solve(x, my, mx, b, ta);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ta[TS][TS];
    memset(ta, 0, sizeof(ta));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &ta[i][j]);
        }
    }

    solve(0, 0, n, n, ta);
    printf("%d\n%d\n", white, blue);
}

