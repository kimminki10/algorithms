#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void testcase() {
    int n; scanf("%d", &n);
    vector<int> heat, eat;
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t); heat.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t); eat.push_back(t);
    }
    vector<pair<int, int> > order;
    for (int i = 0; i < n; i++) {
        order.push_back(make_pair(-eat[i], i));
    }
    sort(order.begin(), order.end());

    int result = 0, beginEat = 0;
    for (int i = 0; i < n; i++) {
        int box = order[i].second;
        beginEat += heat[box];
        result = max(result, beginEat + eat[box]);
    }
    printf("%d\n", result);
}

int main() {
    int T; scanf("%d", &T);

    while(T--) {
        testcase();
    }
}

