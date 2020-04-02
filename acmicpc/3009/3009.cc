#include <cstdio>

int main() {
    int x[1001] = {0,}, y[1001]={0,};
    int rx, ry;
    for (int i = 0; i < 3; i++) {
        int a, b; scanf("%d %d", &a, &b);
        x[a]++, y[b]++;
    }
    for (int i = 0; i < 1001; i++) {
        if (x[i] % 2 == 1) {
            rx = i;
        }
        if (y[i] % 2 == 1) {
            ry = i;
        }
    }
    printf("%d %d\n", rx, ry);
}
