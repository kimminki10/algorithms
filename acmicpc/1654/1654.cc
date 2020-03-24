/*
 * k개의 랜선을 잘라서 n개이상의 랜선을 만들 수 있는 최대 길이
 * input: 이미 가지고 있는 k개의 랜선, 필요한 n개의 랜선 k <= 10000; n <= 1000000;
 * 
 * 그냥 바이너리 서치로 최대 길이를 구하면 되지 않나?
 * 시간 복잡도: klog(k)
 */
#include <cstdio>
#include <vector>
typedef long long LL;
using namespace std;

int k, n;
vector<LL> kv;

LL calcNum(LL length) {
    LL ret = 0;
    for (auto i = kv.begin(); i != kv.end(); i++){
        ret += ((*i) / length);
    }
    return ret;
}

bool isPossible(int length) {
    int num = calcNum(length);
    return n <= num;
}

int main() {
    LL high = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        LL tmp; scanf("%lld", &tmp);
        kv.push_back(tmp);
        high = high < tmp ? tmp: high;
    }

    LL l= 1, r = high, m, ans = -1;
    while (l <= r) {
        m = (l + r) / 2;
        if (isPossible(m)) {
            if (ans < m) {
                ans = m;
            }
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("%lld\n", ans);
}

