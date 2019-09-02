#include <cstdio>
int nums[9];
void combi(int n, int m, int* arr, int arridx) {
    if (m == 0) { 
        for (int i = 0; i < arridx; i++) {
            printf("%d%c", nums[arr[i]], " \n"[i==(arridx-1)]);
        }
        return; 
    }
    
    int small = arridx == 0 ? 0:arr[arridx-1]+1;
    for (int next = small; next < n; next++) {
        arr[arridx] = next;
        combi(n, m - 1, arr, arridx + 1);
    }
}

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    int arr[9] = {0,};
    for (int i = 0; i < 9; i++)
        nums[i] = i+1;
    combi(N, M, arr, 0);
}