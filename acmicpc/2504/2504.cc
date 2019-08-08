#include <cstdio>
#include <cstdlib>
#include <cstring>

int evalp(char sp[31], int &idx);
int eval2p(char sp[31], int &idx);
int eval3p(char sp[31], int &idx);

int main() {
    char strp[31];
    scanf(" %s", strp);

    int idx = 0;
    int result = evalp(strp, idx);
    if (idx == strlen(strp)) {
        printf("%d\n", result);
    }
    else {printf("0\n");}
}

int evalp(char sp[31], int &idx) {
    int result = 0;
    while (1) {
        if (sp[idx] == '(')      { 
            idx++;
            result += eval2p(sp, idx); 
        }
        else if (sp[idx] == '[') { 
            idx++;
            result += eval3p(sp, idx); 
        } else {  break;  }
    }

    return result;
}

int eval2p(char sp[31], int &idx) {
    int result = 2;
    if (sp[idx] == '(' || sp[idx] == '[') {
        result *= evalp(sp, idx);
    } 
    if (sp[idx] == ')') {
        idx++;
        return result;
    } else {
        printf("0\n");
        exit(0);
    }
}

int eval3p(char sp[31], int &idx) {
    int result = 3;
    if (sp[idx] == '(' || sp[idx] == '[') {
        result *= evalp(sp, idx);
    } 
    if (sp[idx] == ']') {
        idx++;
        return result;
    } else {
        printf("0\n");
        exit(0);
    }
}