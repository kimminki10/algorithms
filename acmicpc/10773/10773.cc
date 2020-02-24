#include <cstdio>

int main() {
    int k;
    int arr[100005]={0,};
    int idx = 0;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp == 0) {
            --idx;
        } else {
            arr[idx++] = tmp;
        }
    }

    int s = 0;
    for (int i = 0; i < idx; ++i) {
        s += arr[i];
    }
    printf("%d\n", s);
}
