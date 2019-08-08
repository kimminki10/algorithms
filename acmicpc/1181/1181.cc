#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

const int WORD_SIZE = 51;

struct compare {
    bool operator()(string a, string b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        } else {
            return a < b;
        } 
    }
};

int main() {
    int n;
    char word[WORD_SIZE];

    scanf(" %d", &n);
    set<string, compare> words;

    for (int i = 0; i < n; i++) {
        scanf(" %s", word);
        words.insert(word);
    }

    for (string s : words) {
        printf("%s\n", s.c_str());
    }
}