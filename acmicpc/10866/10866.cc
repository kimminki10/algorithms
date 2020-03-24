#include <cstdio>

const int op_length = 11;
const int d_length = 10004;
class deque{
    public:
    int arr[d_length];
    unsigned int front = 0;
    unsigned int back = 0;

    void push_back(int v) {
        arr[back] = v;
        back = (back + 1) % d_length;
    }

    void push_front(int v) {
        front = (front + d_length-1) % d_length;
        arr[front] = v;
    }

    void pop_front() {
        if (empty()) {
            printf("-1\n");
        } else {
            printf("%d\n", arr[front]);
            front = (front+1) % d_length;
        }
    }

    void pop_back() {
        if (empty()) {
            printf("-1\n");
        } else {
            back = (back+d_length-1) % d_length;
            printf("%d\n", arr[back]);
        }
    }
    
    int size() { 
        return back >= front ? back - front : d_length-front+back;
    }
    bool empty() { return front == back; }
    void get_front() { 
        if (empty()) {
            printf("-1\n");
        } else {
            printf("%d\n", arr[front]); 
        }
    }
    void get_back() { 
        if (empty()) {
            printf("-1\n");
        } else {
            printf("%d\n", arr[(back + d_length-1)%d_length]); 
        }
    }
};

int strcmp(const char a[op_length], const char b[op_length]) {
    int i = 0;
    for (; a[i]; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    return a[i]-b[i];
}

int main() {
    int n;
    scanf("%d", &n);
    
    deque d;
    char op[op_length]; int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_back") == 0){ 
            scanf("%d", &tmp);
            d.push_back(tmp); 
        } else if (strcmp(op, "push_front") == 0){ 
            scanf("%d", &tmp);
            d.push_front(tmp); 
        } else if (strcmp(op, "pop_front") == 0) { d.pop_front(); }
        else if (strcmp(op, "pop_back") == 0) { d.pop_back(); }
        else if (strcmp(op, "size") == 0) { printf("%d\n", d.size()); }
        else if (strcmp(op, "empty") == 0) { printf("%d\n", d.empty()); }
        else if (strcmp(op, "front") == 0) { d.get_front(); }
        else if (strcmp(op, "back") == 0) { d.get_back(); }
        
    }
}
