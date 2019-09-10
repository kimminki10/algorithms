#include <stdio.h>

long long int arr[4000006];

int TN;
long long reserve_sum(int ql, int qr, int idx = 1, int l = 1, int r = TN) {
    if (ql <= l && r <= qr) { return arr[idx]; }
    if (r < ql || qr < l) { return 0; }
    return reserve_sum(ql, qr, idx * 2, l, (l+r)/2) +
        reserve_sum(ql, qr, idx*2+1, (l+r)/2 + 1, r);
}

void change_val(int idx, int val) {
    arr[idx = (TN + idx - 1)] = val;
    for (idx >>= 1; idx; idx >>= 1) {
        arr[idx] = arr[idx*2] + arr[idx*2+1];
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for (TN = 1; TN < N; TN <<= 1);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[TN+i]);
    }
    for (int i = TN-1; i >= 1; i--) {
        arr[i] = arr[i*2] + arr[i*2+1];
    }
    long long int a, b, c;
    for (int i = 0; i < M+K; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            change_val(b, c);
        } else if (a == 2) {
            printf("%lld\n", reserve_sum(b, c));
        }
    }


}