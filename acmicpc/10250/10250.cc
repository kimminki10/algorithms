#include <cstdio>

void testcase() {
    int h,w,n;
    scanf("%d %d %d", &h, &w, &n);

    if (n % h) {
        printf("%d%02d\n", n%h, n/h+1);
    } else {
        printf("%d%02d\n", h, n/h);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    for (;t--;) {
        testcase();
    }
}

