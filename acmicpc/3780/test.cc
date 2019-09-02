#include <stdio.h>


inline int absSub(int a, int b) {
    return (a > b ? a - b: b - a) % 1000;
}


int main() {
    printf("%d\n", absSub(6, 5));
    printf("%d\n", absSub(5, 6));
}