#include <cstdio>


int GCD(int a, int b) {
    return a % b ? GCD(b, a%b) : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[102];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int gcd = GCD(arr[0], arr[i]);
        printf("%d/%d\n", arr[0]/gcd, arr[i]/gcd);
    }
}