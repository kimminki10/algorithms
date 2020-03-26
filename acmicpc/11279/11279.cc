#include <cstdio>
#include <queue>

using namespace std;

int n, arr[100005];
int main() {
    scanf("%d", &n);
    priority_queue<int , vector<int>, less<int> > q;

    for (int i = 0; i < n; i++) {
        int c; scanf("%d", &c);
        if (c == 0) {
            if (q.empty()) {
                printf("0\n");
            }else {
                printf("%d\n", q.top());
                q.pop();
            }
        } else {
            q.push(c);
        }
    }
}
