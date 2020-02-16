#include <cstdio>

int _strcmp(char * a, char * b) {
    int i = 0;
    while(a[i]) {
        if (a[i] != b[i]) {
            break;
        }
        i++;
    }
    return a[i]-b[i];
}

void _strcpy(char *dst, char *src) {
    while((*dst++ = *src++));
}

int checkDup(char g[31][21], int n, char s[21]) {
    for (int i = 0; i < n; i++) {
        if (_strcmp(g[i], s) == 0) {
            return i;
        }
    }
    return -1;
}

void testcase() {
    int n; // 0~30
    scanf("%d", &n);

    char garments[31][21] = {0,};
    int count[31] = {0,};
    int gidx = 0;

    for (int i = 0; i < n; i++) {
        char a[21], b[21] = {0,};
        scanf("%s %s", a,b);

        int re;
        if ((re = checkDup(garments, gidx, b)) == -1) {
            re = gidx++;
            _strcpy(garments[re], b);
        }
        count[re]++;
    }

    int result = 1;
    for (int i = 0; i < gidx; i++) {
        result = result * (count[i] + 1);
    }
    printf("%d\n" ,result - 1);
}

int main() {
    int t;
    scanf("%d", &t);

    for (;t--;) {
        testcase();
    }
}

