#include <cstdio>

int main() {
    char line[101] = {0,};
    scanf("%[^\n]", line);

    int arr[27] = {0,};
    for (int i = 0; line[i] != '\0'; i++) {
        arr[line[i] - 'a']++;
    }

    printf("%d", arr[0]);
    for (int i = 1; i < 26; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}