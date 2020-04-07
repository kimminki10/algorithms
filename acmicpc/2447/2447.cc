#include <cstdio>

int N;
int table[7000][7000];
void solve(int x, int y, int size) {
    if (size == 1) { 
        table[x][y] = 1;
        return;
    }
    int len = size/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            solve(x+len*i, y+len*j, len);
        }
    }
}
int main() {
    scanf("%d", &N);
    solve(0,0,N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }printf("\n");
    }
}