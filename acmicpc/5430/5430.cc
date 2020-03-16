#include <cstdio>
#include <deque>

using namespace std;

void testcase() {
    char p[100005];
    int n;
    scanf("%s\n", p);
    scanf("%d\n", &n);

    deque<int> d;
    int tmp;
    int re = scanf("[%d", &tmp);
    if (re == 1) d.push_back(tmp);
    for (int i = 1; i < n; ++i) {
        scanf(",%d", &tmp);
        d.push_back(tmp);    
    }
    scanf("]\n");
    // input done
    
    bool isReversed = false;
    for (int i = 0; p[i]; i++) {
        char op = p[i];
        if (op == 'R') { isReversed = !isReversed; }
        else if (op == 'D') {
            if (d.empty()) {
                printf("error\n");
                return;
            }
            if (isReversed) { d.pop_back(); }
            else { d.pop_front(); }
        }
    }

    // print
    printf("[");
    if (isReversed) {
        while(!d.empty()) {
            printf("%d", d.back());
            d.pop_back();
            if (!d.empty()) { printf(",");}
        }
    } else {
        while(!d.empty()) {
            printf("%d", d.front());
            d.pop_front();
            if (!d.empty()) { printf(",");}
        }
    }
    printf("]\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        testcase();
    }
}

