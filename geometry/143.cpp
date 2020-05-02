// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double EPS = 1e-7;

bool areEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

struct Point {
    double x;
    double y;

    Point() : x(0), y(0) { };
    Point(double initX, double initY) : x(initX), y(initY) { };
};

double dist(Point A, Point B) {
    double x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y;
    return sqrt(
         pow(x1 - x2, 2) + pow(y1 - y2, 2)
    );
}

bool isRight(Point A, Point B, Point C) {
    return (
        areEqual(
            pow(dist(A, B), 2) + pow(dist(A, C), 2),
            pow(dist(B, C), 2)
        )
        || areEqual(
            pow(dist(A, B), 2) + pow(dist(B, C), 2),
            pow(dist(A, C), 2)
        )
        || areEqual(
            pow(dist(C, B), 2) + pow(dist(A, C), 2),
            pow(dist(B, A), 2)
        )
    );
}

int main() {
    Point A, B, C, D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    int count = 0;
    count += isRight(A, B, C);
    count += isRight(B, C, D);
    count += isRight(C, D, A);
    count += isRight(D, A, B);

    cout << count;
    return 0;
}

#endif