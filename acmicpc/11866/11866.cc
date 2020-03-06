#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int k, n;
    scanf("%d %d", &n, &k);

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        q.push(i+1);
    }    
    printf("<");
    while(true) {
        for (int i = 1; i < k; ++i){
            q.push(q.front());
            q.pop();
        }
        printf("%d", q.front());
        q.pop();
        if (!q.empty()) {
            printf(", ");
        } else {
            break;
        }
    }

    printf(">");
}

