#include <cstdio>

class mh {
    void swap(int &a, int &b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    public:
    int h[100005];
    int len = 0;

    bool isEmpty() {
        return len == 0;
    }
    int top() {
        return h[1];
    }
    void push(int v) {
        h[++len] = v; // 맨뒤에 넣는다.
        int cur = len; 
        while(cur != 1) { // 맨뒤에서 위쪽으로 옮겨온다.
            if (h[cur] < h[cur / 2]) {
                swap(h[cur / 2], h[cur]);
                cur /= 2;
            } else break;
        }
    }
    void pop() {
        h[1] = h[len--]; // 맨뒤 원소를 맨 앞으로 가져온다.
        int cur = 1;
        while(cur * 2 <= len) { // 맨앞에 있는 원소의 위치를 조정해준다.
            int chidx = cur * 2; // left child
            if (chidx + 1 <= len && h[chidx+1] < h[chidx]) {
                chidx++; // right가 더 작아서 right child로 바꿔줌
            } 
            if (h[chidx] < h[cur]) {
                swap(h[chidx], h[cur]);
                cur = chidx;
            } else break;
        }
    }
};

int main() {
    int n;
    scanf("%d", &n);
    mh q;
    for (int i = 0; i < n; i++) {
        int tmp; scanf("%d", &tmp);
        if (tmp == 0) {
            if (q.isEmpty()) {
                printf("0\n");
            } else {
                printf("%d\n", q.top());
                q.pop();
            }
        } else {
            q.push(tmp);
        }
    }
}

