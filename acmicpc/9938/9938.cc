#include <stdio.h>

int p[300001];
int check[300001];

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
        int tmp = find(p[x]);
        p[x] = tmp;
        return tmp;
    }
}

void unionunion(int a, int b) {
    int x = find(p[a]);
    int y = find(p[b]);

    p[x] = y;
    printf("LADICA\n");
}

int main() {
    int N, L;
    int a, b;
    scanf(" %d %d", &N, &L);

    for (int i = 1; i <= L; i++) {
        p[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        scanf(" %d %d", &a, &b);
        if (check[a] == 0) {
            check[a] = 1;
            unionunion(a, b);
        } else if (check[b] == 0) {
            check[b] = 1;
            unionunion(b, a);
        } else if (check[find(a)] == 0) {
            check[find(a)] = 1;
            unionunion(a, b);
        } else if (check[find(b)] == 0) {
            check[find(b)] = 1;
            unionunion(b, a);
        } else {
            printf("SMECE\n");
        }
    }
}