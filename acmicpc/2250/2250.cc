#include <stdio.h>
#include <limits.h>

const int ARRSIZE = 10001;

int tree[ARRSIZE][2];
int level[ARRSIZE];
int length[ARRSIZE];
int minarr[ARRSIZE];
int maxarr[ARRSIZE];

int nodeIdx = 1;
void dfs(int c, int d) {
    if (tree[c][0] > 0){
        dfs(tree[c][0], d+1);
    }

    level[c] = d;
    length[c] = nodeIdx;

    if (minarr[level[c]] > length[c]) {
        minarr[level[c]] = length[c];
    }
    if (maxarr[level[c]] < length[c]) {
        maxarr[level[c]] = length[c];
    }
    nodeIdx += 1;

    if (tree[c][1] > 0) {
        dfs(tree[c][1], d+1);
    }
}

int main() {
    int N;
    int p,l,r;
    int arr[ARRSIZE]= {0,}; // 노드의 등장 횟수 root를 찾는데 쓰임.

    scanf(" %d", &N);

    for (int i = 0; i < ARRSIZE; i++) {
        minarr[i] = INT_MAX;
    }
    for (int i = 0; i < N; i++) {
        scanf(" %d %d %d", &p, &l, &r);
        tree[p][0] = l;
        tree[p][1] = r;

        arr[p] += 1;
        if (l != -1) { arr[l] += 1;}
        if (r != -1) { arr[r] += 1;}
    }

    
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 1)
            dfs(i, 1);
    }

    int result[2] = {0,};
    for (int i = 1; i <= N; i++) {
        int len = maxarr[i] - minarr[i] + 1;
        if (len > result[0]) {
            result[0] = len;
            result[1] = i;
        }
    }
    printf("%d %d\n", result[1], result[0]);
}