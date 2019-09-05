#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > g[10004];  

bool isPossible(long long m, int f1, int f2) {
    bool check[10004] = {false, };
    queue<int> q;
    q.push(f1);
    check[f1] = true;

    while(!q.empty()) {
        int v = q.front(); q.pop();

        if (v == f2) { return true; }
        for (int i = 0; i < g[v].size(); i++) {
            int n = g[v][i].first;
            int maxw = g[v][i].second;

            if (!check[n] && m <= maxw) {
                check[n] = true;
                q.push(n);
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    int f1, f2;
    scanf("%d %d", &N, &M);

    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    scanf("%d %d", &f1, &f2);

    long long l = 0, r = 1000000001, m, ans = -1;
    while(l<=r){
        m=(r+l)/2;
        if (isPossible(m, f1, f2)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    printf("%lld\n", ans);
}