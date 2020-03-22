#include <cstdio>
#include <cstring>

typedef long long ll;
const int AS = 100001;

// min idx segtree
int TN; 
class SegTree {
    public:
    int tree[AS * 4];
    ll h[AS];

    ll minmin(ll a, ll b) {
        if (a == -1) {
            return b;
        } else if (b == -1) {
            return a;
        }
        return h[a] > h[b] ? b : a;
    }

    void init(int N, ll arr[AS]) {
        memset(tree, -1, sizeof(tree));
        memset(h, 0, sizeof(h));
        for (int i = 0; i <= N; i++) {
            h[i] = arr[i];
        }
        for (TN = 1; TN < N; TN <<= 1);
        for (int i = 1; i <= N; i++) {
            tree[TN + i - 1] = i;
        }
        for (int i = TN - 1; i >= 1; i--) {
            tree[i] = minmin(tree[i*2], tree[i*2+1]);
        }
    }

    ll rangeMinIdx(int ql, int qr, int idx = 1, int l=1, int r=TN) {
        if (ql <= l && r <= qr) { return tree[idx]; }
        if (r < ql || qr < l) { return -1; }
        return minmin(rangeMinIdx(ql ,qr, idx * 2, l, (l+r) / 2),
            rangeMinIdx(ql, qr, idx * 2 + 1, (l+r) / 2 + 1, r));
    }

    void printSegtree() {
        for (int i = 1; i <= TN; i <<= 1) {
            for (int j = 0; j < i; j++) {
                printf("%d ", tree[j+i]);
            }printf("\n");
        }
    }
};

SegTree segtree;

ll largest(int l, int r, ll h[AS]) {
    int m = segtree.rangeMinIdx(l, r);
    ll area = (r-l+1) * h[m];
    if (l <= m-1) {
        ll tmp = largest(l, m-1, h);
        if (area < tmp) {
            area = tmp;
        }
    }
    if (m+1 <= r) {
        ll tmp = largest(m+1, r, h);
        if (area < tmp) {
            area = tmp;
        }
    }
    return area;
}

void testcase(int n) {
    ll h[AS];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
    }

    segtree.init(n, h);
    printf("%lld\n", largest(1, n, h));
}

int main() {
    int n; scanf("%d", &n);
    for (; n != 0; scanf("%d", &n)) {
        testcase(n);
    }
}

