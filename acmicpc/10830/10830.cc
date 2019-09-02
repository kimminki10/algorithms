#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

short d[100000000000][5][5];
int n;
long long int b;
set<int> check;

void matmul(short arrA[5][5], short arrB[5][5], short result[5][5]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = (result[i][j] + (arrA[i][k] *arrB[k][j])%1000) % 1000;
            }
        }
    }
}

void solve(long long int bb) {
    if (check.count(bb) == 1) { return; }
    
    check.insert(bb);
    if (bb % 2 == 1) {
        solve(bb - 1);
        matmul(d[1], d[bb-1], d[bb]);
    } else {
        solve(bb/2);
        matmul(d[bb/2], d[bb/2], d[bb]);
    }
}

void printMat(short re[5][5]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", re[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf(" %d %lld", &n, &b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            scanf(" %hd", &d[1][i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        d[0][i][i] = 1;
    }

    check.insert(0);
    check.insert(1);
    solve(b);

    printMat(d[b]);
}
