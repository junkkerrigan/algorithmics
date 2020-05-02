// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int x1, y1, x2, y2, z2;
    cin >> x1 >> y1 >> x2 >> y2 >> z2;

    double f = sqrt(
        pow(x2 - x1, 2) + pow((y2 - y1), 2) + pow(z2, 2)
    );
    double d = 1 / f;

    cout << fixed << setprecision(3) << d << endl;
    return 0;
}

#endif