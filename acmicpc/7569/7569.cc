#include <cstdio>
#include <queue>
using namespace std;

class point {
    public:
    int x, y, z;
    point(int a, int b, int c) {
        x = a; y = b; z = c;
    }
};

int n, m, h;
int box[101][101][101] = {0,}; // box[h][n][m];
int di[6][3] = {{-1, 0, 0}, {1, 0, 0}, 
                {0, -1, 0}, {0, 1, 0}, 
                {0, 0, -1}, {0, 0, 1}};

bool checkRange(int a, int b, int c) {
    if (0 <= a && a < h &&
        0 <= b && b < n &&
        0 <= c && c < m) {
            return true;
    }
    return false;
}

bool allDone() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (box[i][j][l] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d %d", &m, &n, &h);

    queue<point> q, q2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                scanf("%d", &box[i][j][l]);
                if (box[i][j][l] == 1) {
                    q.push(point(l,j,i));
                }
            }
        }
    }

    int result = -1;
    while(!q.empty()) {
        result++;
        while (!q.empty()) {
            point c = q.front(); q.pop();
            q2.push(c);
        }
        
        while (!q2.empty()) {
            point c = q2.front(); q2.pop();

            for (int i = 0; i < 6; i++) {
                int x = c.x + di[i][0];
                int y = c.y + di[i][1];
                int z = c.z + di[i][2];

                if (checkRange(z, y, x) && box[z][y][x] == 0) {
                    box[z][y][x] = 1;
                    q.push(point(x, y, z));
                }
            }
        }
    }

    if (allDone() == false) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }
}
