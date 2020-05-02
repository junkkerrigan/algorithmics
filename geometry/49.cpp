#define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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

struct Fish {
    Point head;
    Point tail;

    Fish() : head(), tail() { };
    Fish(Point head, Point tail) : head(head), tail(tail) { };
};


int main() {
    int l, n, k;
    cin >> l >> n >> k;

    vector<Fish> fishes(n);
    for(int i = 0; i < n; i++)
    {
        cin >> fishes[i].head.x >> fishes[i].head.y >> fishes[i].tail.x >> fishes[i].tail.y;
    }

    Point oak(0, 0);
    int fishesToEatCount = 0;

    for(int i = 0; i < n; i++) {
        if (dist(oak, fishes[i].head) <= l || dist(oak, fishes[i].tail) <= l) {
            fishesToEatCount++;
        } else {
            int dX = fishes[i].tail.x - fishes[i].head.x;
            int dY = fishes[i].tail.y - fishes[i].head.y;

            int a = dY;
            int b = -dX;
            int c = dX * fishes[i].head.y - dY * fishes[i].head.x;

            if (
                pow(c, 2) <= pow(l, 2) * (pow(a, 2) + pow(b, 2))
                && -(c * b) <= (pow(a, 2) + pow(b, 2)) * max(fishes[i].head.y, fishes[i].tail.y)
                && -(c * b) >= (pow(a, 2) + pow(b, 2)) * min(fishes[i].head.y, fishes[i].tail.y)
            ) {
                fishesToEatCount++;
            }
        }
    }

    cout << (fishesToEatCount / k) + 1;
    return 0;
}

#endif
