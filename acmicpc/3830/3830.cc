#include <stdio.h>

const int ARRSIZE = 100000;
int p[ARRSIZE];
int d[ARRSIZE];

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        int tmp = find(p[x]);
        d[x] += d[p[x]];
        p[x] = tmp;
        return tmp;
    }
}

void unionunion(int a, int b, int w) {
    int x = find(a);
    int y = find(b);
    if (x != y) {
        p[x] = y;
        if (d[x] == 0) {
            d[x] = w - d[a] + d[b];
        } else {
            d[x] += d[p[x]];
        }
    }
}

void printlen(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x != y) {
        printf("UNKNOWN\n");
    } else {
        printf("%d\n", d[a] - d[b]);
    }
}
int main() {
    int N, M;
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {break;}
        for (int i = 1; i <= N; i++) {
            p[i] = i;
            d[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            char op;
            int a, b, w;
            scanf(" %c", &op);

            switch(op){
                case '!':
                scanf(" %d %d %d", &a, &b, &w);
                unionunion(a, b, w);
                break;
                case '?':
                scanf(" %d %d", &a, &b);
                printlen(a, b);
                break;
            }
        }
    }
}