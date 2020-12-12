#include <cstdio>
#include <queue>

using namespace std;

int popkth(queue<int>& q, int k) {
    for (int i = 1; i < k; i++) {
        int front = q.front(); q.pop();
        q.push(front);
    }
    int ret = q.front();
    q.pop();
    return ret;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    int r = popkth(q, k);
    printf("<%d", r);
    while (!q.empty()) {
        r = popkth(q, k);
        printf(", %d", r);
    }
    printf(">\n");
}
