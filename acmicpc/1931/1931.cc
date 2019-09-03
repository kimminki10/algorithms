// 시작점 기준으로 정렬 후 끝나는점을 기준으로 정렬하면 될듯?
#include <stdio.h>
#include <algorithm>

using namespace std;

class meet {
public:
    int s;
    int e;
};

bool compareE(meet a, meet b) {
    return a.e < b.e;
}

bool compareS(meet a, meet b) {
    return a.s < b.s;
}

meet arr[100005];
int main() {
    int N; 
    int s, e;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s, &e);
        arr[i].s = s;
        arr[i].e = e;
    }

    sort(arr, arr+N, compareS);
    sort(arr, arr+N, compareE);

    int ans = 1;
    int midx = 0;

    for (int i = 1; i < N; i++){
        if (arr[i].s >= arr[midx].e) {
            midx = i;
            ans += 1;
        }
    }
    printf("%d\n", ans);
}