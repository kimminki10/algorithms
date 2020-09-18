#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>


using namespace std;

int order(const vector<int>& russian, const vector<int> &korean) {
    int n = russian.size(), wins = 0;

    multiset<int> ratings(korean.begin(), korean.end());
    for (int rus = 0; rus < n; rus++) {
        // 가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
        // 가장 레이팅이 낮은 선수와 경기시킨다.
        if (*ratings.rbegin() < russian[rus]) {
            ratings.erase(ratings.begin());
        } else {
            // 그외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 경기 시킨다.
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }
    return wins;
}

void testcase() {
    int n; scanf("%d", &n);

    vector<int> russian;
    vector<int> korean;
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t);
        russian.push_back(t);
    }

    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t);
        korean.push_back(t);
    }

    printf("%d\n", order(russian, korean));
}

int main() {
    int c; scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        testcase();
    }
}
