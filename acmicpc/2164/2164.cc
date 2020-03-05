#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    queue<int> q;
    for (int i = 0 ; i < n; i++) {
        q.push(i+1);
    }
    
    while (q.size() != 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    printf("%d\n", q.front());
}

