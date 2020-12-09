#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

void printInverseWord(char word[1001]) {
    stack<char> stack;

    for (int i = 0; word[i] != '\0'; i++) {
        stack.push(word[i]);
    }

    while(!stack.empty()) {
        char cur = stack.top(); 
        stack.pop();

        printf("%c", cur);
    } 
}

int findWordEndIdx(char line[1001], int startIdx) {
    int i = startIdx;
    for (; ; i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0') {
            break;
        }
    }
    return i;
}

void testcase() {
    char s[1001]={0,};
    scanf(" %[^\n]", s);

    int wordStartIdx = 0;
    for (; ; ) {
        int wordEndIdx = findWordEndIdx(s, wordStartIdx);
        char word[1001] = {0,};
        strncpy(word, s + wordStartIdx, wordEndIdx-wordStartIdx);
        printInverseWord(word);
        wordStartIdx = wordEndIdx + 1;
        
        printf("%c", s[wordEndIdx] == ' '? ' ': '\n');

        if (s[wordStartIdx] == '\0') {
            break;
        }
    }
}


int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        testcase();
    }
}
