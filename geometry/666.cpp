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

struct Segment {
    Point A;
    Point B;

    Segment(Point initA, Point initB) : A(initA), B(initB) { };

    bool contains(Point P) {
        return areEqual(
             0,
             fabs(dist(A, P) + dist(B, P) - dist(A, B))
        );
    }
};

double area(Point A, Point B, Point C) {
    double x = dist(A, B);
    double y = dist(A, C);
    double z = dist(C, B);

    double p = (x + y + z) / 2;

    return sqrt(p * (p - x) * (p - y) * (p - z));
}

int main() {
    Point A, B, C, O;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> O.x >> O.y;

    string answer;
    if (Segment(A, B).contains(O) || Segment(A, C).contains(O) || Segment(C, B).contains(O)) {
        cout << "On";
        return 0;
    }

    double triangleArea = area(A, B, C);
    double chunkArea1 = area(A, O, C);
    double chunkArea2 = area(O, B, C);
    double chunkArea3 = area(A, B, O);

    if (areEqual(triangleArea, chunkArea1 + chunkArea2 + chunkArea3)) {
        cout << "In";
        return 0;
    }

    cout << "Out";
    return 0;
}

#endif