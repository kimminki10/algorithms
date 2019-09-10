#include <stdio.h>
// range chagne
// point query
int TN;
int arr[2000006];

void range_change(int ql, int qr, int c, int idx=1, int l=1, int r=TN) {
    if (ql <= l && r <= qr) { 
        arr[idx] ^= c;
        return; 
    } 
    if (r < ql || qr < l) { return; }

    range_change(ql, qr, c, idx*2, l, (r+l)/2);
    range_change(ql, qr, c, idx*2+1, (r+l)/2 +1, r);
}

int point_query(int idx) {
    int result = arr[idx=(TN+idx-1)];
    for (idx >>= 1; idx; idx >>= 1) {
        result ^= arr[idx];
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    for (TN = 1; TN < n; TN <<= 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[TN+i]);
    }
    int m;
    scanf("%d", &m);
    int t;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &a, &b, &c);
            range_change(a+1, b+1, c);
        } else if (t == 2) {
            scanf("%d", &a);
            printf("%d\n", point_query(a+1));
        }
    }
}