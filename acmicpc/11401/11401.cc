#include <cstdio>
typedef long long ll;
const ll MOD = 1000000007LL;
const int AS = 4000000;
ll fac[AS+1], inv[AS+1];
ll power(ll x, ll y) {
    ll ret = 1;
    for(; y > 0; y /= 2) {
        if (y % 2) {
            ret = (x*ret) % MOD;
        }
        x = (x*x) % MOD;
    }
    return ret;
}
int main() {
    fac[1] = 1;
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == k || k == 0) {
        printf("1\n");
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        fac[i] = (fac[i-1] * i) % MOD;
    }
    inv[n] = power(fac[n], MOD - 2);
    for (int i = n-1; i > 0; --i) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
    ll r = (fac[n] * inv[n-k]) % MOD;
    r = (r*inv[k]) % MOD;
    printf("%lld\n", r);
    return 0;
}
