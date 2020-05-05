#include <cstdio>

const int BOARD_SIZE_MAX = 20; 
char board[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
int H, W;
const int shape[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {1, 0}, {1, -1}}
};

void initValiable() {
    for (int i = 0; i < BOARD_SIZE_MAX; ++i){
        for (int j = 0; j < BOARD_SIZE_MAX; ++j) {
            board[i][j] = '\0';
        }
    }
}

bool isValid(int y, int x, int s) {
    for (int i = 0; i < 3; ++i) {
        const int ny = y + shape[s][i][0];
        const int nx = x + shape[s][i][1];

        if (ny < 0 || ny >= H || nx < 0 || nx >= W){
            return false;
        } else if (board[ny][nx] == '#') {
            return false;
        }
    }
    return true;
}

void setCover(int y, int x, int s, char val) {
    for (int i = 0; i < 3; ++i) {
        const int ny = y + shape[s][i][0];
        const int nx = x + shape[s][i][1];

        board[ny][nx] = val;
    }
}

int solve() {
    int y = -1, x = -1;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == '.') {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    if (y == -1) return 1;
    int ret = 0;
    for (int s = 0; s < 4; ++s) {
        if (isValid(y, x, s)) {
            setCover(y, x, s, '#');
            ret += solve();
            setCover(y, x, s, '.');
        }
    }
    return ret;
}

void testcase() {
    initValiable();
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j) {
            scanf(" %c", &board[i][j]);
        }
    }

    printf("%d\n", solve());
}

int main() {
    int C; scanf("%d", &C);
    for (int i = 0; i < C; ++i) {
        testcase();
    }
}

