#include <cstdio>

int numarr[50];
char oparr[50];
int idx=0;

int main() {
    scanf("%d", &numarr[idx++]);
    int re;
    while((re = scanf("%c%d", &oparr[idx], &numarr[idx])) == 2) {
        idx++;
    }

    for (int i = idx-1; i > 0; i--) {
        if (oparr[i] == '+') {
            numarr[i-1] = numarr[i]+ numarr[i-1];
            numarr[i]=0;
        }
    }

    int result = numarr[0];
    for (int i = 1; i < idx; i++) {
        if (oparr[i]=='-') {
            result -= numarr[i];
        }
    }
    printf("%d\n", result);
}