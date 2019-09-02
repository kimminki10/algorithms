#include <cstdio>
#include <string>
#include <map>

using namespace std;

int p[200000];
int n[200000];

int find(int x) {
    if (x == p[x]) {return x;}
    else return p[x] = find(p[x]);
}
int unionunion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b){
        p[a] = b;
        n[b] += n[a];
        n[a] = 1;
    }
    return n[b];
}
void testCase() {
    int F; // under 100000
    scanf("%d", &F);
    
    for (int i = 0; i < F*2; i++) {
        p[i] = i;
        n[i] = 1;
    }

    char a[21], b[21];
    map<string, int> m;
    int mcount = 0;
    for (int i = 0 ; i < F; i++) {
        scanf(" %s %s", a, b);
        if (m.count(a) == 0){
            m[a] = mcount++;
        }
        int anum = m[a];
        if (m.count(b) == 0) {
            m[b] = mcount++;
        }
        int bnum = m[b];

        printf("%d\n", unionunion(anum,bnum));
    }
}

int main() {
    int T; 
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        testCase();
    }
}