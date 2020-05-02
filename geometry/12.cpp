// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const double EPS = 1e-4;

bool areEqual(double a, double b, bool details = false) {
    if (details) {
        cout << a - b << '\n';
    }
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

    void print() {
        cout << x << ' ' << y;
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

    double length() {
        return dist(A, B);
    }

    bool contains(Segment S2);

    bool hasOneCommonPointWith(Segment S2);

    Point intersectionPointWith(Segment S2);

    bool onLineWith(Segment S2);
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

    bool operator!=(Line L2) {
        return !(*this == L2);
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

        double x = (c2 * b1 - c1 * b2) / (b2 * a1 - a2 * b1);
        double y = (c1 * a2 - c2 * a1) / (b2 * a1 - a2 * b1);

        return {x, y};
    }

    double distToPoint(Point P) {
        return fabs(a * P.x + b * P.y + c) / sqrt(pow(a, 2) + pow(b, 2));
    }
};

bool Segment::contains(Segment S2) {
    Segment S1(*this);
    if (Line(S1) != Line(S2)) {
        return false;
    }

    if (S1.length() > S2.length()) {
        Point closerToS1A(
            dist(S1.A, S2.A) < dist(S1.A, S2.B)
                ? S2.A
                : S2.B
        );
        Point closerToS1B(
            dist(S1.B, S2.A) <= dist(S1.B, S2.B)
                ? S2.A
                : S2.B
        );

        return areEqual(
            S1.length(),
            dist(S1.A, closerToS1A) + S2.length() + dist(closerToS1B, S1.B)
        );
    } else {
        Point closerToS2A(
            dist(S2.A, S1.A) < dist(S2.A, S1.B)
                ? S1.A
                : S1.B
        );
        Point closerToS2B(
            dist(S2.B, S1.A) <= dist(S2.B, S1.B)
                ? S1.A
                : S1.B
        );

        return areEqual(
            S2.length(),
            dist(S2.A, closerToS2A) + S1.length() + dist(closerToS2B, S2.B)
        );
    }
}

bool Segment::hasOneCommonPointWith(Segment S2) {
    Segment S1 = *this;
    Line L1(S1);
    Line L2(S2);
    Point A1 = S1.A, B1 = S1.B;
    Point A2 = S2.A, B2 = S2.B;

    if (
        A1 == B1 || A1 == B2
        || A2 == B1 || A2 == B2
    ) {
        return true;
    }
    if (L1.isParallelTo(L2)) {
        return false;
    }

    try {
        Point O(L1.intersectionPointWith(L2));
//        O.print();
//        cout << '\n';
        return S1.contains(O) && S2.contains(O);
    } catch (const char*) {
        return false;
    }
}

Point Segment::intersectionPointWith(Segment S2) {
    if (!this->hasOneCommonPointWith(S2)) {
        throw "Passed segment do not has the only one intersection point with this";
    }

    return Line(*this).intersectionPointWith(Line(S2));
}

bool Segment::onLineWith(Segment S2) {
    return Line(*this) == Line(S2);
}

Point symbolBase, symbolTop;
Point pictureLeft, pictureRight;
double pictureHeight;

double cutLength() {
    Segment fallenSymbol(symbolBase, symbolTop);
    Segment pictureBase(pictureLeft, pictureRight);
    double symbolHeight = fallenSymbol.length();
    Line pictureBaseLine(pictureBase);
    Line fallenSymbolLine(fallenSymbol);

    if (fallenSymbol.hasOneCommonPointWith(pictureBase)) {
        if (fallenSymbol.onLineWith(pictureBase)) {
            return 0;
        }
        if (
            fallenSymbol.contains(pictureBase.A)
            || fallenSymbol.contains(pictureBase.B)
            || pictureBase.contains(fallenSymbol.A)
            || pictureBase.contains(fallenSymbol.B)
        ) {
            return 0;
        }

        try {
            Point intersectionPoint(fallenSymbol.intersectionPointWith(pictureBase));

            double distToCut = dist(symbolBase, intersectionPoint);
            double cutLength = sqrt(pow(symbolHeight, 2) - pow(distToCut, 2));

//            cout << distToCut << ' ' << symbolHeight << ' ' << cutLength << '\n';
            return fmin(pictureHeight, cutLength);
        } catch (const char*) {
            return 0;
        }
    }
    if (!fallenSymbol.onLineWith(pictureBase)) {
        return 0;
    }
    if (pictureBase.contains(fallenSymbol)) {
        return fmin(symbolHeight, pictureHeight);
    }

    double distToA = dist(symbolBase, pictureBase.A);
    double distToB = dist(symbolBase, pictureBase.B);
    double cutLength;

    if (distToA < distToB) {
        if (symbolHeight <= distToA) {
            return 0;
        }
        cutLength = sqrt(pow(symbolHeight, 2) - pow(distToA, 2));
    } else {
        if (symbolHeight <= distToB) {
            return 0;
        }
        cutLength = sqrt(pow(symbolHeight, 2) - pow(distToB, 2));
    }

    return fmin(pictureHeight, cutLength);

    // TODO: handle all cases when are on one line
}


void test();

#ifdef DEV

int main() {
    test();
    return 0;
}

#else

int main() {
    cin >> symbolBase.x >> symbolBase.y;
    cin >> symbolTop.x >> symbolTop.y;
    cin >> pictureLeft.x >> pictureLeft.y;
    cin >> pictureRight.x >> pictureRight.y;
    cin >> pictureHeight;

    cout << fixed << setprecision(3) << cutLength();
    return 0;
}

#endif

void print(vector<double> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ' ';
        }
    }
}
void test() {
    vector<vector<double>> testCases = {
        // 0
        { 0, 1, 2, 3, 2, 1, 0, 3, 1234 },
        // 1
        { 0, 1, 2, 3, 2, 1, 0, 3, 0.5 },
        // 2
        { 0, 0, 2, 2, 1, 1, 3, -1, 1234 },
        // 3
        { 0, 0, 2, 2, 1, 1, 3, -1, 0.5 },
        // 4
        { -2, -2, 1, 2.001, 1, -2, 1, 2, 1234 },
        // 5
        { -2, -2, 1, 2.001, 1, -2, 1, 2, 0.5 },
        // 6
        { 0, 0, 2, 2, 1, 0, 1, 3, 1234 },
        // 7
        { 0, 0, 2, 2, 1, 0, 1, 3, 0.5 },
        // 8
        { 1, 1, 6, 1, 4, 0, 4, 5, 6 },
        // 9
        { -1, -1, 0, 1, 0, 2, 1, -1, 6231 },
        // 10
        { 0, 0, 2, 2, 1, 1, 5, 5, 10 },
        // 11
        { 0, 0, 2, 2, 1, 1, 5, 5, 1 },
        // 12
        { 2, 0, 2, 2, 2, 1, 2, 5, 1.7 },
        // 13
        { 2, 0, 2, 2, 2, 1, 2, 5, 17 },
        // 14
        { 2, -1, 2, 1, 2, -2, 2, 2, 1 },
        // 15
        { 2, 0, 2, 2, 2, 1, 2, 5, 26 },
    };

    vector<double> expected = {
        // 0
        2.44949,
        // 1
        0.500,
        // 2
        0.000,
        // 3
        0.000,
        // 4
        0.000,
        // 5
        0.000,
        // 6
        2.44949,
        // 7
        0.500,
        // 8
        4.000,
        // 9
        0.000,
        // 10
        2.44949,
        // 11
        1.000,
        // 12
        1.700,
        // 13
        1.732,
        // 14
        1.000,
        // 15
        2.000,
    };

    for(int i = 0; i < testCases.size(); i++) {
        symbolBase.x = testCases[i][0];
        symbolBase.y = testCases[i][1];
        symbolTop.x = testCases[i][2];
        symbolTop.y = testCases[i][3];
        pictureLeft.x = testCases[i][4];
        pictureLeft.y = testCases[i][5];
        pictureRight.x = testCases[i][6];
        pictureRight.y = testCases[i][7];
        pictureHeight = testCases[i][8];

        double expectedValue = expected[i];
        double receivedValue = cutLength();

        cout
            << "#" << i << '\n'
            << "given: "; print(testCases[i]); cout << '\n'
            << "expected: " << fixed << setprecision(3) << expectedValue << '\n'
            << "received: " << fixed << setprecision(3) << receivedValue << '\n'
            << "passed: " << (areEqual(expectedValue, receivedValue) ? "YES" : "NO") << '\n'
            << '\n';
    }
}

#endif
