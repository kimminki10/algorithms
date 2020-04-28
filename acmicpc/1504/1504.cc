#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 801;
const int INF = 987654321;
int N, E, a, b, c;
vector<pair<int, int> > graph[MAX]; // node, distance

vector<int> dijkstra(int start, int end) {
    vector<int> distance(end, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    pq.push({0, start}); // cost, node

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distance[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int neighbor = graph[cur][i].first; 
            int neighborDistance = cost + graph[cur][i].second;

            if (distance[neighbor] > neighborDistance) {
                distance[neighbor] = neighborDistance;
                pq.push({ neighborDistance, neighbor });
            }
        }
    }
    return distance;
}

int main() {
    scanf("%d %d", &N, &E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    N++;

    int v1, v2;
    scanf("%d %d", &v1, &v2);
    vector<int> result = dijkstra(1, N);
    vector<int> t1 = dijkstra(v1, N);
    vector<int> t2 = dijkstra(v2, N);
    int answer = min({result[v1] + t1[v2] + t2[N-1], result[v2] + t2[v1] + t1[N-1]});
    if(answer >= INF || answer < 0) {
        printf("-1\n");
    } else {
        printf("%d\n", answer);
    }
}

