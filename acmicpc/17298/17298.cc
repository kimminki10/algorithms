#include <cstdio>
#include <stack>
#include <vector>
#include <memory.h>

using namespace std;

int n;
int arr[1000006];
int result[1000006];

void prevnge() {
    stack<pair<int, int> > s;

    s.push(make_pair(0, arr[0]));
    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top().second < arr[i]) {
            result[s.top().first] = arr[i]; 
            s.pop();
        }
        if (i == n - 1) {
            result[i] = -1;
            break;
        }
        s.push(make_pair(i, arr[i]));
    }

    printf("%d", result[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", result[i]);
    }
    printf("\n");
}

int main() {
    memset(result, -1, sizeof(result));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    prevnge();
}
