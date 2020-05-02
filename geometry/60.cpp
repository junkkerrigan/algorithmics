// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x;
    double y;

    Point() : x(0), y(0) { };
    Point(double initX, double initY) : x(initX), y(initY) { };
};

double area(const vector<Point>& polygon)
{
    double ans = 0;
    for (int i = 0; i < polygon.size(); i++)
    {
        if (i == 0) {
            ans += (polygon.back().x - polygon[i].x) * (polygon.back().y + polygon[i].y);
        } else {
            ans += (polygon[i - 1].x - polygon[i].x) * (polygon[i - 1].y + polygon[i].y);
        }
    }
    return fabs(ans / 2);
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for(int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    cout << fixed << setprecision(3) << area(polygon);
    return 0;
}

#endif