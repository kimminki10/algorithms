#include <cstdio>
#include <cstring>

class queue {
    public:

    const static int queue_max = 2000006;
    int arr[queue_max];
    int fidx, bidx;

    queue() {
        fidx = 0;
        bidx = 0;
    }

    void push(int v) {
        arr[bidx] = v;
        bidx = (bidx+1) % queue_max;
    }

    int pop() {
        if (empty()) { return -1; }
        int result = arr[fidx];
        fidx = (fidx+1) % queue_max;
        return result;
    }

    int size() { return bidx-fidx; }

    bool empty() { return bidx == fidx; }

    int front() { 
        if (empty()) { return -1; }
        return arr[fidx]; 
    }

    int back() { 
        if (empty()) { return -1; }
        return arr[bidx-1]; 
    }
};

int main() {
    int N, v;
    char op[10];
    queue q;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%s", op);
        if (strcmp(op, "push") == 0) {
            scanf("%d", &v);
            q.push(v);
        } else if (strcmp(op, "pop") == 0) {
            printf("%d\n", q.pop());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", q.size());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", q.empty());
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", q.front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", q.back());
        }
    }
}

