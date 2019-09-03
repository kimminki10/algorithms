#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

class jam {
public:
    int m, v; // mass value
};

bool compareJam(jam a, jam b) {
    return a.m < b.m;
}

jam arr[300005];
int bag[300005];
int bidx = 0;
long long maxvalue(int N, int K) {
    long long sum = 0;
    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < K; i++) {
        for (; j < N && arr[j].m <= bag[i]; j++) {
            pq.push(arr[j].v);
        }
        if (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
    }
    
    return sum;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(arr[i].m), &(arr[i].v));
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &bag[i]);
    }

    sort(arr, arr+N, compareJam); // 무게당 가격이 비싼 순으로 정렬
    sort(bag, bag+K);
    long long ans = maxvalue(N,K);

    printf("%lld\n", ans);
}