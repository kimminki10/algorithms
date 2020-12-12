#include <cstdio>
#include <stack>

using namespace std;

void flushStack(stack<char>& s) {
    while (!s.empty()) {
        char c = s.top(); s.pop(); 
        printf("%c", c);
    }
}

int main() {
    stack<char> word;
    char line[100001];

    scanf("%[^\n]", line);
    printf("debug: %s\n", line);

    int idx = 0;
    char cur = line[idx++];
    while (cur != '\0' && cur != '\n') {
        if (cur == '<') {
            flushStack(word);
            while (cur != '>') {
                printf("%c", cur);
                cur = line[idx++];
            }
            printf("%c", cur);
        } else if (cur != ' ') {
            word.push(cur);
        } else if (cur == ' ') {
            flushStack(word);
            printf(" ");
        }
        cur = line[idx++];
    }
    flushStack(word);
}
