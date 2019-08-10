#include <cstdio>
#include <array>

const int ARR_SIZE = 100001;
using namespace std;
void checkTeam(array<int, ARR_SIZE> &arr, int n, int idx, array<int, ARR_SIZE> &team) {
    int i;
    for (i = idx; team[i] != 2 && team[i] != -1; i = arr[i]) {
        team[i]++;
    }
    for (i = idx; team[i] != 2 && team[i] != -1; i = arr[i]) {
        if (team[i] == 1) {
            team[i] = -1;
        }
    }
}

int solve(array<int, ARR_SIZE> &arr, int n) {
    int result = 0;
    array<int, ARR_SIZE> team = {0};
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            checkTeam(arr, n, i, team);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            result += 1;
        }
    }
    return result;
}

int main() {
    int T, n;
    array<int, ARR_SIZE> arr = {0};
    scanf(" %d", &T);

    while(T--) {
        scanf(" %d", &n);

        int tmp;
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &arr[i]);
        }

        printf("%d\n", solve(arr, n));
    }
}