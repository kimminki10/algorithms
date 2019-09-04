#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int k, n;
    char op;

    priority_queue<pair<int,int> > maxq;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > minq;
    int check[1000006] = {0,};

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf(" %c %d", &op, &n);
        if (op == 'I') {
            maxq.push({n, i});
            minq.push({n, i});
            check[i] = 1;
        } else if (op == 'D') {
            if (n == 1) {
                while (!maxq.empty() && (check[maxq.top().second] == 0)) {// 동기화
                    maxq.pop();
                }
                if (!maxq.empty()) {
                    check[maxq.top().second] = 0;
                    maxq.pop();
                }
            } else { // n = -1
                while (!minq.empty() && (check[minq.top().second] == 0)) { 
                    minq.pop();
                }
                if (!minq.empty()) {
                    check[minq.top().second] = 0;
                    minq.pop();
                }
            }
        }
    }

    while (!maxq.empty() && !check[maxq.top().second]) {
        maxq.pop();
    }
    while (!minq.empty() && !check[minq.top().second]) {
        minq.pop();
    }
    if (minq.empty() && maxq.empty()) {
        printf("EMPTY\n");
    } else {
        printf("%d %d\n", maxq.top().first, minq.top().first);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve();
    }
}