#include <cstdio>

void checkmap(int x, int y, int map[52][52], int mark[52][52]) {
    mark[x][y] = 1;
    if (map[x+1][y] == 1 && mark[x+1][y] == 0) { checkmap(x+1,y,map,mark); }
    if (map[x+1][y+1] == 1 && mark[x+1][y+1] == 0) { checkmap(x+1,y+1,map,mark); }
    if (map[x+1][y-1] == 1 && mark[x+1][y-1] == 0) { checkmap(x+1,y-1,map,mark); }
    if (map[x-1][y] == 1 && mark[x-1][y] == 0) { checkmap(x-1,y,map,mark); }
    if (map[x-1][y+1] == 1 && mark[x-1][y+1] == 0) { checkmap(x-1,y+1,map,mark); }
    if (map[x-1][y-1] == 1 && mark[x-1][y-1] == 0) { checkmap(x-1,y-1,map,mark); }
    if (map[x][y-1] == 1 && mark[x][y-1] == 0) { checkmap(x,y-1,map,mark); }
    if (map[x][y+1] == 1 && mark[x][y+1] == 0) { checkmap(x,y+1,map,mark); }
}

void something(int w, int h) {
    int map[52][52] = { 0, };
    int mark[52][52] = { 0, };

    for (int j = 1; j <= h; j++) {
        for (int i = 1; i <= w; i++) {
            scanf(" %d", &map[i][j]);
        }
    }

    int num = 0;
    for (int j = 1; j <= h; j++) {
        for (int i = 1; i <= w; i++) {
            if (map[i][j] == 1 && mark[i][j] == 0) {
                num += 1;
                checkmap(i, j, map, mark);
            }
        }
    }
    printf("%d\n", num);
}

int main() {
    int w, h;
    while (1) {
        scanf(" %d %d", &w, &h);
        if (w == 0 && h == 0) { break; }

        something(w, h);
    }
}