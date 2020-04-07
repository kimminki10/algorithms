#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int v_num, e_num, k;
vector<pair<int,int> > graph[20001];    // <v, w> graph[u];

vector<int> dijkstra(int start, int vertex) {
    vector<int> result(vertex, 987654321);
    result[start] = 0;  // 자기자신과의 거리는 0

    priority_queue< pair<int, int> > q; // <w, v>
    q.push(make_pair(0, start));

    while(!q.empty()) {
        pair<int,int> c = q.top();q.pop();
        int w = -c.first;
        int v = c.second;
        
        if (result[v] < w) { continue; }

        int num = graph[v].size();
        for (int i = 0; i < num; i++) {
            pair<int, int> near = graph[v][i];
            int nv = near.first;
            int nw = w + near.second;
            if (result[nv] > nw) {
                result[nv] = nw;
                q.push(make_pair(-nw, nv));
            }
        }
    }
    return result;
}
int main() {
    scanf("%d %d\n%d", &v_num, &e_num, &k);
    int u, v, w;
    for (int i = 0; i < e_num; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }
    v_num++; // 
    vector<int> result = dijkstra(k, v_num);
    for (int i = 1; i < v_num; i++) {
        if (result[i] == 987654321) { printf("INF\n"); }
        else { printf("%d\n", result[i]); }
    }
}

