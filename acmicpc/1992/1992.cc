#include <stdio.h>

int m[64][64];

int checkAll(int sx, int sy, int ex, int ey) {
    for (int i = sx; i < ex; i++) {
        for (int j = sy; j < ey; j++) {
            if (m[i][j] != m[sx][sy]) {
                return -1;
            }
        }
    }
    return m[sx][sy];
}

void solve(int sx, int sy, int ex, int ey) {
    int re;
    if ((re = checkAll(sx, sy, ex, ey)) != -1) {
        printf("%d", re);
        return;
    }

    printf("(");
    solve(sx, sy, (sx+ex)/2, (sy+ey)/2);
    solve(sx, (sy+ey)/2, (sx+ex)/2, ey);
    solve((sx+ex)/2, sy, ex, (sy+ey)/2);
    solve((sx+ex)/2, (sy+ey)/2, ex, ey);
    printf(")");
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf(" %1d", &m[i][j]);

    solve(0,0,N,N);
    printf("\n");
}