#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int ARR_SIZE = 20001;
int k;
int v, e;

vector<int> t[ARR_SIZE];
short check[ARR_SIZE];

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    check[s] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (int i : t[v]) {
            if (check[i] == 0) {
                q.push(i);
                check[i] = -check[v];
            } else if (check[i] == check[v]) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    for (int i = 1; i <= v; i++) {
        if (check[i] == 0) {
            if (!bfs(i)) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    scanf(" %d", &k);
    while (k--) {
        scanf(" %d %d", &v, &e);
        for (int i = 0; i < e; i++) {
            int v1, v2;
            scanf(" %d %d", &v1, &v2);
            t[v1].push_back(v2);
            t[v2].push_back(v1);
        }

        solve();

        for (int i = 1; i <= v; i++) {
            check[i] = 0;
            t[i].clear();
        }
    }
}