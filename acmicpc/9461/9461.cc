#include <cstdio>

long long int p[102];

void testcase() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", p[n]);
}

int main() {
    int t;
    scanf("%d", &t);

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    p[6] = p[3] + p[5]; // 3
    p[7] = p[2] + p[6]; // 4
    p[8] = p[1] + p[7]; // 5
    p[9] = p[4] + p[8]; // 7
    p[10] = p[5] + p[9]; // 9
    p[11] = p[6] + p[10]; // 12
    p[12] = p[7] + p[11]; // 16
    p[13] = p[8] + p[12]; // 21

    for (int i = 10; i <= 100; i++) {
        p[i] = p[i-1] + p[i-5];
    }
    while(t--) {
        testcase();
    }
}