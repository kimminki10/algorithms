#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 1001;

void dfs(vector<int> g[MAX_SIZE], int v, int visited[MAX_SIZE]);
void bfs(vector<int> g[MAX_SIZE], int v);
void dfs_print_visited(int visited[MAX_SIZE], int n);

int main() {
    vector<int> g[MAX_SIZE];
    int n, m, v;
    scanf(" %d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i < n+1; i++) {
        sort(g[i].begin(), g[i].end());
    }


    int visited[MAX_SIZE] = {0,};
    dfs(g, v, visited);
    dfs_print_visited(visited, n);

    bfs(g, v);
}

void dfs(vector<int> g[MAX_SIZE], int v, int visited[MAX_SIZE]) {
    static int num = 1;
    visited[v] = num++; 
    for (int i : g[v]) {
        if (visited[i] != 0) {
            dfs(g, i, visited);
        }
    }
}

void dfs_print_visited(int visited[MAX_SIZE], int n) {
    for (int i = 1; i < n + 1; i++) {
        printf("%d\n", visited[i]);
    }
}


void bfs(vector<int> g[MAX_SIZE], int v) {
    printf("bfs\n");
}