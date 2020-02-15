#include <cstdio>
const int MODULO = 10007;
int d[1003][1003];

// pascal's rule
int binomial_coefficient(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }else if (d[n][k] == 0) {
        d[n][k] = (binomial_coefficient(n-1,k-1) + binomial_coefficient(n-1, k))%MODULO;
    }  
    return d[n][k];
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d\n", binomial_coefficient(n,k));
}

