#include <cstdio>

class Heap {
    bool (*cmp)(int a, int b);
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp; 
    }
    public:

    Heap(bool (*cmpf)(int a, int b)) {
        cmp = cmpf;
    }
    int h[100005];
    int len = 0;

    void push(int v) {
        h[++len] = v;
        int cur = len;
        while(cur != 1) { // 뒤부터 위로 올라오며 위치를 찾는다.
            if ((*cmp)(h[cur], h[cur/2])) {
                swap(h[cur], h[cur/2]);
                cur /= 2;
            } else break; // 제 위치를 찾았다!
        }
    }

    int pop() {
        int ret = h[1];
        h[1] = h[len--];
        int cur = 1;
        while(cur * 2 <= len) {
            int chidx = cur * 2; // left
            if (chidx+1 <= len && (*cmp)(h[chidx+1], h[chidx])) {
                chidx++;
            }
            if ((*cmp)(h[chidx], h[cur])) {
                swap(h[chidx], h[cur]);
                cur = chidx;
            } else break;
        }
        return ret;
    }

    int top() {
        return h[1];
    }

    void printh() {
        for (int i = 1; i <= len; i++) {
            printf("%d ", h[i]);
        } printf("\n");
    }
};

bool max(int a, int b) {
    return a > b;
}

bool min(int a, int b) {
    return a < b;
}

int main() {
    int n; scanf("%d", &n);

    Heap minq(&min);
    Heap maxq(&max);
    minq.push( 10001);
    maxq.push(-10001);

    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        
        int l = maxq.top();
        int r = minq.top();
        if (v > r) { minq.push(v); }
        else { maxq.push(v); }

        if (minq.len > maxq.len) { maxq.push(minq.pop()); }
        if (maxq.len - minq.len >= 2) {
            minq.push(maxq.pop());
        }

        printf("%d\n", maxq.top());
    }
}

