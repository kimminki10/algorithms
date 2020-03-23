#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PAIR;
#define X first
#define Y second

const LL MAX = 1000000000000ll;
PAIR point[500005];
int n;

LL square(LL a) {
    return a*a;
}

LL dist(PAIR a, PAIR b) {
    return square(a.X - b.X) + square(a.Y - b.Y);
}

bool op(PAIR a, PAIR b) {
    if (a.Y != b.Y) {
        return a.Y < b.Y;
    } else {
        return a.X < b.X;
    }
}

LL solve(PAIR * point, int s, int e) {
    if (e - s == 1) {
        return MAX;
    }
    int m = (s+e)/2;
    LL d =  min(solve(point, s, m), solve(point, m, e));
    vector<PAIR> v;
    LL sep = point[m].X;
    for (int i = s; i < e; i++) {
        if (square(point[i].X - sep) <= d) {
            v.push_back(point[i]);
        }
    }
    sort(v.begin(), v.end(), op);
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size() && j < i + 7; j++) {
            d = min(d, dist(v[i], v[j]));
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &point[i].X, &point[i].Y);
    }
    sort(point, point + n);
    printf("%lld\n", solve(point, 0, n));
}