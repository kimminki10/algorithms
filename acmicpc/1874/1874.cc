#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<int> s;

    int n;
    scanf(" %d", &n);

    queue<int> result;
    queue<char> record;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf(" %d", &tmp);
        result.push(tmp);        
    }

    for (int i = 1; i <= n; i++) {
        if (i <= result.front()) {
            s.push(i);
            record.push('+');
            if (result.front() == s.top()) {
                while (!result.empty() && !s.empty()
                     && result.front() == s.top() ) { 
                    result.pop();
                    s.pop();
                    record.push('-'); 
                }
            }
        }
    }

    if (!result.empty() || !s.empty()) {
        printf("NO\n");
        return 0;
    }

    for (; !record.empty(); ) {
        printf("%c\n", record.front());
        record.pop();
    }
}