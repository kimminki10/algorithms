#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void testcase() {
    int n; scanf("%d", &n);
    vector<int> l;

    for (int i = 0 ; i < n; i++) {
        int t; scanf("%d", &t);
        l.push_back(t);
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < l.size(); i++) {
        pq.push(l[i]);
    }
    int ret = 0;

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        pq.push(a+b);
        ret += a+b;
    }
    printf("%d\n", ret);
}
int main() {
    int c; scanf("%d", &c);
    while(c--) {
        testcase();
    }
}

