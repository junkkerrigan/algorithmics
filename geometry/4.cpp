//#define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-7;

bool areEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(
        (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    );
}

int main() {
    double x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double distBetweenCenters = dist(x1, y1, x2, y2);

    if (areEqual(distBetweenCenters, 0)) {
        if (areEqual(r1, r2)) {
            cout << -1;
        } else {
            cout << 0;

        }
    } else if (distBetweenCenters < fabs(r1 - r2)) {
        cout << 0;
    } else if (areEqual(distBetweenCenters, fabs(r1 - r2))) {
        cout << 1;
    } else if (distBetweenCenters < r1 + r2) {
        cout << 2;
    } else if (areEqual(distBetweenCenters, r1 + r2)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}

#endif
