#include <iostream>
#include <string>

using namespace std;

string compare(string x, string y)
{
    string ans = "=";

    if (x.length() > y.length()) {
        ans = ">";
    } else if (x.length() < y.length()) {
        ans = "<";
    } else {
        for (int i = 0; i < x.length(); i++) {
            if (x[i] > y[i]) {
                ans = ">";
                break;
            } else if (x[i] < y[i]) {
                ans = "<";
                break;
            }
        }
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << compare(a, b);
    return 0;
}