#include <cstdio>
#include <vector>

using namespace std;

const int AVAILABLE = 0;
const int DISAVAILABLE = -1;

class Point {
public:
    int x, y;
    int value = -1;
    int available[9] = {0,};
    int availableCount = 9;

    void makrDisavailable(int idx) {
        if (available[idx] == AVAILABLE) {
            available[idx] = DISAVAILABLE;
            availableCount--;
            if (availableCount == 1) {
                value = idx;
            }
        }
    }
    void setX(int a) {
        x = a;
    }

    void setY(int b) {
        y = b;
    }

    void setValue(int v) {
        value = v;
    }
};

class Board {
public:
    Point p[9][9];

    void xTest(Point * inP) {
        if (inP->value != 0) { return; }
        for (int i = 0; i < 9; i++) {
            if (i == inP->x) { continue; }
            int boardNum = p[i][inP->y].value;
            if (boardNum == 0) { continue; }
            inP->makrDisavailable(boardNum);
        }
    }

    void yTest(Point * inP) {
        if (inP->value != 0) { return; }
        for (int i = 0; i < 9; i++) {
            if (i == inP->y) { continue; }
            int boardNum = p[inP->x][i].value;
            if (boardNum == 0) { continue; }
            inP->makrDisavailable(boardNum);
        }
    }

    void squareTest(Point * inP) {
        if (inP->value != 0) { return; }
        int startx = (inP->x / 3) * 3;
        int starty = (inP->x / 3) * 3;
        int endx = startx + 3;
        int endy = starty + 3;
        for (int i = startx; i < endx; i++) {
            for (int j = starty; j < endy; j++) {
                if (i == inP->x && j == inP->y) { continue; }
                int boardNum = p[i][j].value;
                if (boardNum == 0) { continue; }
                inP->makrDisavailable(boardNum);
            }
        }
    }
};

Board b;

int main() {
    vector<Point *> z;
    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %d", &tmp);
            b.p[i][j].setX(i);
            b.p[i][j].setY(j);
            b.p[i][j].setValue(tmp);
            if (tmp == 0) { z.push_back( &b.p[i][j] ); }
        }
    }

    for (Point * p : z) {
        b.xTest(p);
        b.yTest(p);
        b.squareTest(p);
    }
}