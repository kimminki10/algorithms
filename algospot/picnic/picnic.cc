#include <cstdio>

const int MAX_N = 10;
int n, m; 
bool areFriends[MAX_N][MAX_N] = {false, };

int solve(bool taken[MAX_N]) {
    int firstFree = -1;

    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;

    int ret = 0;
    for (int pairWith = firstFree+1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += solve(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

void initializeValiable(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            areFriends[i][j] = false;
        }
    }
}

void testcase() {
    initializeValiable();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        areFriends[a][b] = true;
        areFriends[b][a] = true;
    }
    bool taken[MAX_N] = {false, };
    printf("%d\n", solve(taken));
}

int main() {
    int C; scanf("%d", &C);

    for (int i = 0; i < C; ++i) {
        testcase();
    }
}

