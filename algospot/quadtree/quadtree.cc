#include <string>
#include <iostream>

using namespace std;

string reverse(string::iterator& it) {
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w') return string(1, head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight +upperLeft + upperRight;
}

void testcase() {
    string image;
    cin >> image;
    string::iterator it = image.begin();
    string ret = reverse(it);
    cout << ret << endl;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int C; cin >> C;
    for (int i = 0; i < C; ++i) {
        testcase();
    }
}

