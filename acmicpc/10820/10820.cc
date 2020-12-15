#include <cstdio>
#include <cctype>

void printInfo(char* line) {
    int SMALL = 0;
    int UPPER = 0;
    int SPACE = 0;
    int NUM = 0;

    int idx = 0;
    char cur = line[idx++];
    while(cur != '\0') {
        if (isupper(cur)) {
            UPPER++;
        } else if (islower(cur)) {
            SMALL++;
        } else if (cur == ' ') {
            SPACE++;
        } else if (isalnum(cur)) {
            NUM++;
        }
        cur = line[idx++];
    }

    printf("%d %d %d %d\n", SMALL, UPPER, NUM, SPACE);
}

int main() {
    char line[101] = {0,};

    while(scanf("%[^\n]", line) != EOF) {
        printInfo(line);
        getchar();
    }
}