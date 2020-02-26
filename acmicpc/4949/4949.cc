#include <cstdio>
#include <cstdlib>
#include <cstring>

void solveline(char *s) {
    char stack[102];
    int idx = 0;
    while (*s != '\0') {
        char c = *s;
        if (c == '(' || c== '[') {
            stack[idx++] = c;
        } else if (c==')'||c==']'){
            if (idx > 0 && 
                ((stack[idx-1] == '(' && c== ')') ||
                (stack[idx-1] == '[' && c== ']'))) {
                idx--;
            }  
            else {
                printf("no\n");
                return;
            }
        }
        s++;
    }
    if (idx != 0) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
}

int main() {
    char *s = NULL;
    size_t len = 0;
    for (;;) {
        getline(&s, &len, stdin);
        if (strcmp(s, ".") == 0 || strcmp(s, ".\n") == 0) {
            break;
        }
        
        solveline(s);
    }
    free(s);
}

