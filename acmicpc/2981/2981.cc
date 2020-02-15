#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int GCD(int a, int b)  {
    return a % b ? GCD(b, a%b) : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[102];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);
    int gcd = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        gcd = GCD(gcd, arr[i] - arr[i-1]);
    }
    set<int> result;
    for (int i = 2; i * i <= gcd; i++) {
        if (gcd % i == 0){
            result.insert(i);
            result.insert(gcd / i);
        }
    }
    result.insert(gcd);

    set<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++) {
        if (*iter != 1) {
            printf("%d ", *iter);
        }
    }
}