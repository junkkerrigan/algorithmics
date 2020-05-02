// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, angleInDegrees;
    cin >> a >> b >> angleInDegrees;

    double angleInRadians = (M_PI * angleInDegrees) / 180;
    double area;

    if (angleInDegrees == 0) {
        area = 0;
    } else if (angleInDegrees == 90) {
        area = a * b * sqrt(2);
    } else if (
        (1 / tan(angleInRadians)) > (a / (b * sqrt(2)))
    ) {
        area = pow(a, 2) / (2 * cos((M_PI * angleInDegrees) / 180));
    }
    else {
        area = ((a * sqrt(2)) - (b  / tan(angleInRadians))) * b / sin(angleInRadians);
    }

    cout << fixed << setprecision(3) << area;
    return 0;
}

#endif
