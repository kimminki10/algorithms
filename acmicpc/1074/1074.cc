#include <stdio.h>

long long int N, r, c;
int count=-1;
bool find = false;
void solve(long long int sx, long long int sy, 
            long long int ex, long long int ey) {
    if (find == true) { return; }
    if ((ex - sx) == 2){
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                count += 1;
                if (sx+i == r && sy+j == c) {
                    find = true;
                    return;
                }
            }
        }
        return;
    }
    solve(sx, sy, (sx+ex)/2, (sy+ey)/2);
    solve(sx, (sy+ey)/2, (sx+ex)/2, ey);
    solve((sx+ex)/2, sy, ex, (sy+ey)/2);
    solve((sx+ex)/2, (sy+ey)/2, ex, ey);
}
int main() {
    scanf("%lld %lld %lld", &N, &r, &c);
    long long int n = 1;
    for (int i = 0; i < N; i++) {
        n *= 2;
    }
    solve(0,0,n,n);
    printf("%d\n", count);
}