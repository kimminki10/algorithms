#include <cstdio>
#include <vector>
using namespace std;

int n, cnt=1, tmp;
vector<int> v;

void printv() {
    printf("printv\n");
    for (auto i = v.begin(); i != v.end(); i++) {
        printf("%d ", *i);
    }printf("cnt: %d\n", cnt);
}
int main() {
    scanf("%d", &n);
    v.push_back(1000006);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        printf("tmp: %d ", tmp);
        if (tmp > v.back()) { 
            printf("pushback\n");
            v.push_back(tmp); cnt++; }
        else {
            auto low = lower_bound(v.begin(), v.end(), tmp);
            printf("lowerbound: %d\n", *low);
            *low = tmp;
        }
        printv();
    }
    printf("%d\n", cnt);
}

