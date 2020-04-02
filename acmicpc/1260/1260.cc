#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, m, start;
int tree[1001][1001] = {0,};
int visit[1001] = {0,};
void dfs(int v) {
    visit[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= 1000; i++) {
        if (tree[v][i] == 1 && visit[i] != 1) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = 1;

    while (!q.empty()) {
        int c = q.front(); q.pop();
        printf("%d ", c);
        for (int i = 1; i <= 1000; i++) {
            if (tree[c][i] == 1 && visit[i] != 1) {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}
int main() {
    scanf("%d %d %d", &n, &m, &start);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        tree[a][b] = 1;
        tree[b][a] = 1;
    }
    dfs(start); printf("\n");
    memset(visit, 0, sizeof(visit));
    bfs(start);
}

