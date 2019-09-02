#include <stdio.h>

const int arrSize = 500000;
long long int arr[arrSize];
long long int tmp[arrSize];

long long mergesort(int s, int e) { // swap 횟수 return
    if(e - s <= 1){
        if(arr[s] > arr[e]){
            int tmp = arr[s];
            arr[s] = arr[e];
            arr[e] = tmp;
            return 1;
        }
        return 0;
    }
    int m = (s + e) / 2;
    long long result = mergesort(s, m) + mergesort(m+1, e);

    int i = s;
    int j = m+1;
    int idx = s;
    while(i <= m && j <= e) {
        if (arr[i] <= arr[j]) { tmp[idx++] = arr[i++]; }
        else {
            result += (m-i+1);
            tmp[idx++] = arr[j++];
        }
    }

    while (i <= m) tmp[idx++] = arr[i++];
    while (j <= e) tmp[idx++] = arr[j++];

    for (i = s; i <= e; i++) {
        arr[i] = tmp[i];
    }
    return result;
}

int main() {
    int N;

    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %lld", &arr[i]);
    }

    printf("%lld\n", mergesort(0, N-1));
}