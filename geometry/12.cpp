#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-7;

bool areEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

struct Point {
    double x;
    double y;

    Point() : x(0), y(0) { };
    explicit Point(double initCoord) : x(initCoord), y(initCoord) { };
    Point(double initX, double initY) : x(initX), y(initY) { };

    bool operator==(Point P2) {
        double x1 = x, y1 = y;
        double x2 = P2.x, y2 = P2.y;

        return (
            areEqual(x1, x2) && areEqual(y1, y2)
        );
    }
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

    Segment() : A(), B() { };
    Segment(Point initA, Point initB) : A(initA), B(initB) { };

    bool operator==(Segment S2) {
        Point A1 = A, B1 = B;
        Point A2 = S2.A, B2 = S2.B;

        return (
            (A1 == B2 && B1 == A2)
            || (A1 == B1 && B2 == A2)
        );
    }

    bool contains(Point P) {
        return areEqual(
                0,
                fabs(dist(A, P) + dist(B, P) - dist(A, B))
        );
    }

    bool contains(Segment S2) {

    }

    bool hasOneCommonPoint(Segment S2);
};

// represents line as aX + bY + c = 0
struct Line {
    double a;
    double b;
    double c;

    Line() : a(0), b(0), c(0) { };
    Line(Point A, Point B) {
        double x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y;
        a = y2 - y1;
        b = x1 - x2;
        c = y1 * x2 - x1 * y2;
    };
    explicit Line(Segment S) : Line(S.A, S.B) { };

    bool operator==(Line L2) {
        double a1 = a, a2 = L2.a;
        double c1 = c, c2 = L2.c;

        if (!isParallelTo(L2)) {
            return false;
        }
        if (c1 == 0) {
            return c2 == 0;
        }
        if (c2 == 0) {
            return false;
        }
        return areEqual(a1 / a2, c1 / c2);
    }

    bool isParallelTo(Line L2) {
        double a1 = a, b1 = b;
        double a2 = L2.a, b2 = L2.b;

        return areEqual(a1 * b2 - a2 * b1, 0);
    }

    bool hasOneCommonPointWith(Line L2) {
        return !isParallelTo(L2);
    }

    Point intersectionPointWith(Line L2) {
        if (!hasOneCommonPointWith(L2)) {
            throw "Passed line is parallel to this one, so there`s no intersection point";
        }

        double a1 = a, b1 = b, c1 = c;
        double a2 = L2.a, b2 = L2.b, c2 = L2.c;

        double y = (c2 * a1 - c1 * a2) / (b2 * a1 - a2 * b1);
        double x = (c2 * b1 - c1 * b2) / (b2 * a1 - a2 * b1);

        return {x, y};
    }
};

bool Segment::hasOneCommonPoint(Segment S2) {
    Line L1(*this);
    Line L2(S2);
    Point A1 = A, B1 = B;
    Point A2 = S2.A, B2 = S2.B;

    if (
        A1 == B1 || A1 == B2
        || A2 == B1 || A2 == B2
    ) {
        return true;
    }
    if (L1.isParallelTo(L2)) {

    }

}

int main() {
    Point symbolBottom, symbolTop;
    Point pictureLeft, pictureRight;
    double pictureHeight;

    cin >> symbolBottom.x >> symbolBottom.y;
    cin >> symbolTop.x >> symbolTop.y;
    cin >> pictureLeft.x >> pictureLeft.y;
    cin >> pictureRight.x >> pictureRight.y;
    cin >> pictureHeight;


    return 0;
}

