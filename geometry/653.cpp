// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string answer;
    if (a + b <= c || a + c <= b || b + c <= a) {
        answer = "IMPOSSIBLE";
    } else if (
        a * a + b * b < c * c
        || a * a + c * c < b * b
        || b * b + c * c < a * a
    ) {
        answer = "OBTUSE";
    } else if (
        a * a + b * b == c * c
        || a * a + c * c == b * b
        || b * b + c * c == a * a
    ) {
        answer = "RIGHT";
    } else {
        answer = "ACUTE";
    }

    cout << answer;
    return 0;
}

#endif