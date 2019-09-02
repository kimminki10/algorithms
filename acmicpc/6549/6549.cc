#include <stdio.h>

int n;
long long h[100000];

long long solve(int s, int e) {
    long long smallest = h[s];
    int sidx = s;
    for (int i = s; i < e; i++) {
        if (h[i] < smallest) {
            smallest = h[i];
            sidx = i;
        }
    }

    long long result = (e-s) * smallest;
    if (sidx > s) { 
        long long t = solve(s, sidx); 
        if (t > result) {result = t;}
    }
    if (sidx < e-1) {
        long long t = solve(sidx+1, e);
        if (t > result) {result = t;}
    }
    return result;
}

int main() {
    while(true) {
        scanf("%d", &n);
        if (n == 0) { return 0; }
        for (int i = 0; i < n; i++) 
            scanf(" %lld", &h[i]);

        printf("%lld\n", solve(0, n));
    }
}