#include <stdio.h>
#include <queue>

using namespace std;
int cards[500005];
bool isPossible(long long m, int N, int M) {
    // M이 1일 경우만 해보자
    int count = 0;
    int pc = 0;
    int s = 0;
    
    for (int k = 0; k < M; k++) {
        int check[500005] = {0,};

        for (int i = s; i < N; i++) {
            if (check[cards[i]] == 0) {
                check[cards[i]] += 1;
                count += 1;
                if (count == m) {
                    if (pc == M) {
                        return true;
                    } else {
                        pc += 1;
                        s += 1;
                        count = 0;
                        break;
                    }
                }
            } else {
                for (int j = s; j < i; j++) {
                    if (cards[j] == cards[i]) {
                        s = j+1;
                        break;
                    } else {
                        count -= 1;
                        check[cards[j]] -= 1;
                    }
                }
            }
        }
    }
    
    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    long long l = 0, r = N, m, ans = -1;
    while (l <= r) {
        m=(l+r)/2;
        if (isPossible(m, N, M)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    printf("%lld\n", ans);
}