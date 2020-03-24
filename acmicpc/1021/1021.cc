#include <cstdio>

const int q_length = 100;

class deque {
    public:
    int arr[q_length];
    int front = 0;
    int back = 0;

    int addmod(int v) { return (v+1) % q_length; }
    int submod(int v) { return (v-1+q_length) % q_length; }

    void push_back(int v) { 
        arr[back] = v; 
        back = addmod(back);
    }

    void push_front(int v) {
        front = submod(front);
        arr[front] = v;
    }

    void front_pop() { front = addmod(front); } // op 1
    void back_pop() { back = submod(back); }

    int size() { return (back + q_length - front) % q_length; }
    void circular_left() { // op 2
        push_back(arr[front]);
        front_pop();
    }

    void circular_right() { // op 3
        int tmp = submod(back);
        push_front(arr[tmp]);
        back_pop();
    }

    int get_index(int v) {
        int result = 0;
        for (int i = front; i != back; i = addmod(i), result++) {
            if (v == arr[i]) {
                return result;
            }
        }
        return -1;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    deque q;

    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        int idx; scanf("%d", &idx);

        int cur = q.get_index(idx);
        int left = cur;
        int right = q.size() - cur;

        if (left < right) {
            result += left;
            for (int j = 0; j < left; j++) {
                q.circular_left();
            }
        } else {
            result += right;
            for (int j = 0; j < right; j++) {
                q.circular_right();
            }
        }
        q.front_pop();
    }

    printf("%d\n", result);
}

