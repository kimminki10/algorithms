#include <cstdio>

const int INF = 9999;
const int CLOCK_NUM = 16;
const int SWITCH_NUM = 10;
int clocks[CLOCK_NUM];
bool connection[SWITCH_NUM][CLOCK_NUM] = {false, };

void FillConnection() {
    int coninfo[SWITCH_NUM][5] = {
        {  0,  1,  2, -1, -1 },
        {  3,  7,  9, 11, -1 },
        {  4, 10, 14, 15, -1 },
        {  0,  4,  5,  6,  7 },
        {  6,  7,  8, 10, 12 },
        {  0,  2, 14, 15, -1 },
        {  3, 14, 15, -1, -1 },
        {  4,  5,  7, 14, 15 },
        {  1,  2,  3,  4,  5 },
        {  3,  4,  5,  9, 13 },
    };
    for (int i = 0; i < SWITCH_NUM; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (coninfo[i][j] != -1) {
                connection[i][coninfo[i][j]] = true;
            }
        }
    }
}
bool areAligned() {
    for (int i = 0; i < CLOCK_NUM; ++i) {
        if (clocks[i] != 12) {
            return false;
        }
    }
    return true;
}
inline int min(int a, int b) {
    return a > b? b: a;
}
void push(int swtch) {
    for (int i = 0; i < CLOCK_NUM; ++i) {
        if (connection[swtch][i]) {
            clocks[i] += 3;
            if (clocks[i] == 15) clocks[i] = 3;
        }
    }
}
int solve(int swtch) {
    if (swtch == SWITCH_NUM) return areAligned() ? 0 : INF;
    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(swtch + 1));
        push(swtch);
    }
    return ret;
}
void testcase() {
    for (int i = 0; i < CLOCK_NUM; ++i) {
        scanf("%d ", &clocks[i]);
    }

    int result = solve(0);
    if (result == INF) { result = -1;  }
    printf("%d\n", result);
}
int main() {
    FillConnection();
    int C; scanf("%d", &C);
    for (int i = 0; i < C; ++i) {
        testcase();
    }
}

