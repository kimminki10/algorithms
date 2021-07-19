#include <cstdio>
#include <cstring>

class MingStack {
	public:
	int arr[100001] = {0,};
	int idx = 0;
	
	bool isEmpty() { return idx == 0; }
	int size() { return idx; }
	
	
	int top() {
		if (isEmpty()) { return -1;	}
		return arr[idx-1];
	}
	void push(int x) {
		arr[idx++] = x;
	}
	
	int pop() {
		if (isEmpty()) { return -1;	}
		return arr[--idx];
	}
	
};

int main() {
	int N;
	scanf("%d", &N);
	char op[10];
	
	MingStack s;
	
	for (int i = 0; i < N; i++) {
		scanf(" %s", op);
		
		if (strcmp(op, "push") == 0) {
			int x; scanf(" %d", &x);
			s.push(x);
		} else if (strcmp(op, "top") == 0) { printf("%d\n", s.top()); }
		else if (strcmp(op, "empty") == 0) { printf("%d\n", s.isEmpty()); }
		else if (strcmp(op, "pop") == 0) { printf("%d\n", s.pop()); }
		else if (strcmp(op, "size") == 0) { printf("%d\n", s.size()); }
	}
}