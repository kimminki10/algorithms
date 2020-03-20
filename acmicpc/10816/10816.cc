#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    map<int,int> card;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        card[tmp]++;
    }
    int m;
    scanf("%d", &m);
    int c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &c);
        auto v = card.find(c);
        if (v == card.end()) {
            printf("0 ");
        } else {
            printf("%d ", v->second);
        }
    }printf("\n");
}

