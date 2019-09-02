#include <stdio.h>

inline int absSub(int a, int b) {
    return (a > b ? a - b: b - a) % 1000;
}

int find(int c[20001], int d[20001], int I) {
    if (c[I] == I) {
        return I;
    } else {
        int tmp = find(c,d, c[I]);
        d[I] += d[c[I]];
        c[I] = tmp;
        return tmp;
    }
}

void unionCenter(int c[20001], int d[20001], int I, int J) {
    c[I] = J;
    d[I] = (absSub(I, J)) % 1000;
}

int main() {
    int T;
    scanf(" %d", &T);

    for (;T--;) {
        int N;  // 기업의 수
        scanf(" %d", &N);
        int c[20001] = {0,}; // company
        int d[20001] = {0,}; // distance
        char op = '\0';
        int I, J;

        for (int i = 1; i <= N; i++)
            c[i] = i;

        for(; op != 'O';) {
            scanf(" %c", &op);
            switch(op) {
                case 'E':
                scanf(" %d", &I);
                find(c, d, I);
                printf("%d\n", d[I]);
                break;

                case 'I':
                scanf(" %d %d", &I, &J);
                unionCenter(c, d, I, J);
                break;

                case 'O':
                break;

                default:
                printf("input error?\n");
                break;
            }
        }
    }
}