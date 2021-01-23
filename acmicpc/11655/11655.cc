#include <cstdio>
#include <cctype>

int main() {
    char line[101] = {0,};
    scanf("%[^\n]", line);

    int idx = 0;
    char cur = line[idx++];
    while (cur != '\0') {
        if (isupper(cur)) {
            cur -= 'A';
            cur = (cur + 13) % 26;
            cur += 'A';
        } else if (islower(cur)) {
            cur -= 'a';
            cur = (cur + 13) % 26;
            cur += 'a';
        }
        
        printf("%c", cur);
        cur =  line[idx++];
    }
    printf("\n");
}