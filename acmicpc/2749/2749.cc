/*
 * n 은 1000000000000000000 까지 가능하다.....메모이 제이션 가능할까? 주기가 있을지도.. 걍 포기할래..
 * 수열로 나타내보자
*/
#include <cstdio>
#include <cstring>

typedef long long ll;
const ll MOD = 1000000LL;
void matsquare(ll d[2][2], ll s[2][2]) {
    ll ret[2][2];
    memset(ret, 0, sizeof(ret));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ret[i][j] = (ret[i][j] + d[i][k] * s[k][j]) % MOD;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            d[i][j] = ret[i][j];
        }
    }
}

int main() {
    ll n; 
    scanf("%lld", &n);

    ll m[2][2] = {{1,1}, {1,0}};
    ll res[2][2] = {{1,0}, {0,1}}; // equi
    n -= 1;
    
    for (; n > 0; n /= 2) {
        if (n % 2 == 1) {
            matsquare(res, m);
        }
        matsquare(m, m);
    }

    printf("%lld\n", res[0][0]);
}

