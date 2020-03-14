#include <cstdio>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    if (v-a<0) {
        printf("1\n");
    } else {
        printf("%d\n", (v-b-1)/(a-b) + 1);
    }
}

