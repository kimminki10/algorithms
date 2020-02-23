#include <cstdio>

int aa(int n, int mod) {
    int count = 0;
    for (long long int i = mod; n / i >= 1; i *= mod) {
        count += n / i;
    }
    return count;
}

inline int minmin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a, b, c, d, e, f;

    a = aa(n, 2);
    c = aa(n-m, 2);
    e = aa(m, 2);

    b = aa(n, 5);
    d = aa(n-m, 5);
    f = aa(m, 5);

    printf("%d\n" , minmin(a-c-e, b-d-f));
}

