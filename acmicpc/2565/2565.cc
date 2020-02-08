#include <cstdio>
#include <algorithm>

using namespace std;
const int SIZE = 102;

int d[SIZE]; // 증가하는 부분수열 값 그 자체
pair<int, int> arr[SIZE];

int main() {
    int n; // eq-less 100
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d %d", &(arr[i].first), &(arr[i].second));
    }
    sort(arr, arr+n);

    int idx = 0;
    int len = 0;
    d[0] = arr[0].second;
    for (int i = 1; i < n; ++i) {
        if (d[idx] < arr[i].second) {
            d[++idx] = arr[i].second;
        } else {
            int tmp = lower_bound(d, d+idx, arr[i].second) - d; // 들어갈자리를 찾아서 넣는다.
            d[tmp] = arr[i].second;
            ++len;
        }
    }

    printf("%d\n", len);
}