#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;
long long int mintree[400005];
long long int maxtree[400005];

int TN;
long long reserve_min(int ql, int qr, int idx = 1, int l = 1, int r = TN) {
    if (ql <= l && r <= qr) { return mintree[idx]; }
    if (r < ql || qr < l) { return 0x3f3f3f3f; }
    return min(reserve_min(ql, qr, idx * 2, l, (l+r)/2),
        reserve_min(ql, qr, idx*2+1, (l+r)/2 + 1, r));
}
long long reserve_max(int ql, int qr, int idx = 1, int l = 1, int r = TN) {
    if (ql <= l && r <= qr) { return maxtree[idx]; }
    if (r < ql || qr < l) { return 0; }
    return max(reserve_max(ql, qr, idx * 2, l, (l+r)/2),
        reserve_max(ql, qr, idx*2+1, (l+r)/2 + 1, r));
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    memset(mintree, 0x3f, sizeof(mintree));

    for (TN = 1; TN < N; TN <<= 1);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &mintree[TN+i]);
        maxtree[TN+i] = mintree[TN+i];
    }
    for (int i = TN-1; i >= 1; i--) {
        mintree[i] = min(mintree[i*2], mintree[i*2+1]);
        maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
    }
    long long int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%lld %lld", &a, &b);
        printf("%lld %lld\n", reserve_min(a, b), reserve_max(a, b));
    }


}