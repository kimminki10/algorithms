#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    char ab[100] = {0,};
    char cd[100] = {0,};

    scanf("%s", ab);
    scanf("%s", ab+strlen(ab));

    scanf("%s", cd);
    scanf("%s", cd+strlen(cd));

    printf("%ld\n", atol(ab)+atol(cd));
}