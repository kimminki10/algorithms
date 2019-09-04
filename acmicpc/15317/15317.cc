#include <stdio.h>
#include <algorithm>
using namespace std;

long long int N, M, X;
long long int fix[100005];
long long int budget[100005];

bool isPossible(long long int m){
    long long shortageSum = 0;
    for (int i = 0; i < m; i++){
        long long sub = fix[i] - budget[i + M-m];
        if (sub > 0) {
            shortageSum += sub;
        }
    }
    if (shortageSum > X) { return false; }
    else return true;
}

int main() {
    scanf("%lld %lld %lld", &N, &M, &X);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &fix[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%lld", &budget[i]);
    }

    sort(fix, fix+N);
    sort(budget, budget+M);

    long long int small = N > M ? M:N;
    long long int l=0, r=small, m; 
    long long ans;
    while (l<=r) {
        m=(l+r)/2;
        if (isPossible(m)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    printf("%lld\n", ans);
}