#include <cstdio>

int main() {
    double n, k;
    double result = 1;
    scanf("%lf %lf", &n, &k);
    for (int i = 0; i < k; i++) {
        result *= (n-i)/(k-i);
    }
    printf("%.0lf\n", result);
}

