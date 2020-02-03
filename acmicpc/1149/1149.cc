#include <cstdio>

long long int price[1003][3]; // r g b

long long int min(long long int a, long long int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    scanf("%lld %lld %lld", &price[0][0], &price[0][1], &price[0][2]);
    for (int i = 1; i < n; i++) {
        scanf("%lld %lld %lld", &price[i][0], &price[i][1], &price[i][2]);
        price[i][0] += min(price[i-1][1], price[i-1][2]);
        price[i][1] += min(price[i-1][2], price[i-1][0]);
        price[i][2] += min(price[i-1][1], price[i-1][0]);
    }
    printf("%lld\n", min(min(price[n-1][0], price[n-1][1]), price[n-1][2]));
}