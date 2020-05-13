#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_PANEL_NUM = 20000;

int solve(int h[MAX_PANEL_NUM], int left, int right) {
    if (left == right) return h[left];
    int mid = (left + right) / 2;
    int ret = max(solve(h, left, mid), solve(h, mid+1, right));

    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, height *2);
    while(left < lo || hi < right) {
        if (hi <right &&(lo == left || h[lo-1] < h[hi+1])) {
            ++hi;
            height = min(height, h[hi]);
        } else {
            --lo;
            height = min(height, h[lo]);
        }

        ret = max(ret, height * (hi - lo +1));
    }

    return ret;
}

void testcase() {
    int N; cin >> N;
    int height[MAX_PANEL_NUM] = {0, };
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }
    int ret = solve(height, 0, N);
    printf("%d\n", ret);
}
int main() {
    ios::sync_with_stdio(false);
    int C; cin >> C;
    for (int i = 0; i < C; ++i) {
        testcase();
    }
}

