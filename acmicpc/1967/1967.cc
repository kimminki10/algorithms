#include <stdio.h>
#include <vector>

using namespace std;
 
vector<pair<int, int> > v[10001];
int result = 0;
int n;

int dfs(int s) {
    int a = 0, b = 0, sum; // a 가 가장 긴거 b 는 그다음 긴거
    for (auto i: v[s]) {
        sum = dfs(i.first) + i.second;
        if (sum > a) {
            b = a;
            a = sum;
        } else if (sum > b) {
            b = sum;
        }
    }
    if (result < (a+b)) { result = a + b; }
    return a;
}
int main() {
    scanf("%d", &n);

    int p,c,w;
    for (int i = 1; i < n; i++) {
        scanf(" %d %d %d", &p, &c, &w);
        v[p].push_back({c, w});
    }
    dfs(1);
    printf("%d\n", result);
}