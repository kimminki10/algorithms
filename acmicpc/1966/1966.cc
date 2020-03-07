#include <cstdio>

const int q_length = 101;

class item {
    public:
    int priority;
    bool isTarget;
};

class printer_queue {
    public:
    item arr[q_length];
    int front = 0;
    int back = 0;

    void push_back(item v) {
        arr[back] = v;
        back = (back+1) % q_length;
    }

    void pop() { front = (front+1) % q_length; }

    bool is_empty() { return front == back; }

    void print_target() {
        int count = 0;
        while (!is_empty()) {
            item c = arr[front];
            bool f = false;
            for (int i = (front+1) % q_length; i != back; i = (i+1) % q_length) {
                if (arr[i].priority > c.priority) { // 우선순위가 높은 것을 찾으면
                    push_back(c);
                    pop();
                    f = true;
                    break;
                }
            }
            if (f == false) { 
                ++count;
                if (arr[front].isTarget) {
                    printf("%d\n", count);
                    return;
                }
                pop(); 
            }
        }
    }
};

void testcase() {
    int n, m;
    scanf("%d %d", &n, &m);

    printer_queue q;
    for (int i = 0; i < n; i++) {
        item tmp;
        scanf("%d", &(tmp.priority));
        tmp.isTarget = i == m;

        q.push_back(tmp);
    }
    q.print_target();
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        testcase();
    }
}

