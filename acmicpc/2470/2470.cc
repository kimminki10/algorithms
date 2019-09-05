#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long arr[100005];

bool compare(long long a, long long b) {
    return abs(a) < abs(b);
}

int main() {
    long long int N;
    
    scanf("%lld", &N);
    for (long long i = 0 ; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+N, compare);

    for (int i = 0; i < N; i++) {
        printf("%lld\n", arr[i]);
    }
    long long s;
    long long small = abs(arr[0] + arr[1]);
    long long ans = 1;
    for (int i = 1; i < N; i++) {
        s = arr[i] + arr[i-1];
        if (abs(s) < small) {
            small = abs(s);
            ans = i;
        }
    }
    
    long long int bigger = arr[ans] > arr[ans-1] ? arr[ans] : arr[ans-1];
    long long int smaller = arr[ans] < arr[ans-1] ? arr[ans] : arr[ans-1];
    printf("%lld %lld\n", smaller, bigger);
}