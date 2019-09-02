#include <stdio.h>

char m[6][6];
int count = 0;

bool t[6][6];

bool isPossible(int check[6][6], int x, int y) {
    if (0 <= x && x < 5 && //경계값 체크
        0 <= y && y < 5 && 
        check[x][y] && !t[x][y]) {            // 방문 여부 체크
        return true;
    }
    return false;
}
int adjacencycheck(int check[6][6], int x, int y) {
    t[x][y] = true;
    int result = 1;
    if (isPossible(check, x+1, y)) { result += adjacencycheck(check,  x+1, y); }
    if (isPossible(check, x-1, y)) { result += adjacencycheck(check,  x-1, y); }
    if (isPossible(check, x, y+1)) { result += adjacencycheck(check,  x, y+1); }
    if (isPossible(check, x, y-1)) { result += adjacencycheck(check,  x, y-1); }

    return result;
}

void checkCondition(int * arr, int arridx) {
    int check[6][6] = {0,};
    int snum=0;
    int x;
    int y;
    for (int i = 0; i < 7; i++) {
        x = arr[i] % 5;
        y = arr[i] / 5;
        check[x][y] = 1;
        if (m[x][y] == 'S') { snum += 1;}
    }

    for (int i = 0; i < 6; i++) { 
        for (int j = 0; j < 6; j++)
            t[i][j] = false; 
    }
    if (adjacencycheck(check, x, y) != 7) { return; }

    if (snum >= 4) {
        count += 1;
    }
}

void combi(int n, int m, int* arr, int arridx) {
    if (m == 0) { 
        checkCondition(arr, arridx);
        return; 
    }
    
    int small = arridx == 0 ? 0:arr[arridx-1]+1;
    for (int next = small; next < n; next++) {
        arr[arridx] = next;
        combi(n, m - 1, arr, arridx + 1);
    }
}


int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf(" %c", &m[i][j]);
        }
    }

    int choice[7] = {0,};
    combi(25, 7, choice, 0);

    printf("%d\n", count);
}