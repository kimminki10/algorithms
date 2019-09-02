#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class node {
public:
    int value;
    int absv;
    
    node(int v) {
        value = v;
        if (v < 0) { absv = -v; }
        else { absv = v; }
    }
    bool operator <(const node&o) const{
        if (absv == o.absv) {
            return value > o.value;
        }
        return absv > o.absv;
    }
};

int arridx = 0;
int main() {
    int N;
    priority_queue<node> pq;
    scanf("%d", &N);
    int tmp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if (tmp != 0) {
            pq.push(node(tmp));
        } else if (tmp == 0) {
            if (!pq.empty()) {
                printf("%d\n", pq.top().value);
                pq.pop();
            } else {
                printf("0\n");
            }
        }
    }
}