#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

struct t {
    double x, y;
    t() {
        x = 0;
        y = 0;
    }
    t(double x, double y) {
        this->x = x;
        this->y = y;
    }
    t operator+(t &tt) { return t(this->x + tt.x, this->y + tt.y); }

    t operator-(t &tt) { return t(this->x - tt.x, this->y - tt.y); }

    bool operator==(t &p) { return ((x == p.x) && (y == p.y)); }

    bool operator!=(t &p) { return !(*this == p); }

    bool t_is_line_segment(t &t1, t &t2) {
        t t3 = *this;
        t a = t2 - t1;
        t b = t3 - t1;
        double sa = a.x * b.y - b.x * a.y;
        if (sa > 0.0) return false;
        if (sa < 0.0) return false;
        if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return false;
        if (a.length() < b.length()) return false;
        if (t1 == t3) return false;
        if (t2 == t3) return false;
        return true;
    }
    double distance(const t &p) {
        double a = this->x - p.x;
        double b = this->y - p.y;
        return sqrt(a * a + b * b);
    }

    double length(void) { return sqrt(x * x + y * y); }
};

struct line {
    double a, b, c;
    line(const t &t1, const t &t2) {
        a = t1.y - t2.y;
        b = t2.x - t1.x;
        c = t1.x * t2.y - t2.x * t1.y;
    }
};

bool intersect(const line &l1, const line &l2, t &res) {
    if (l1.a * l2.b == l2.a * l1.b)
        return false;
    double g = l1.a * l2.b - l2.a * l1.b;
    res.x = -(l1.c * l2.b - l2.c * l1.b) / g;
    res.y = -(l1.a * l2.c - l2.a * l1.c) / g;
    return true;
}

int main() {

    t x0, x1, x2, x3, m;

    double h = 6, answer = 0;

    cin >> x0.x >> x0.y >> x1.x >> x1.y >> x2.x >> x2.y >> x3.x >> x3.y >> h;
    double x0x1_d = x0.distance(x1);
    if (((x3.y - x2.y) * (x0.x - x1.x) - (x3.x - x2.x) * (x0.y - x1.y)) == 0) {
        if (x0.t_is_line_segment(x2, x3)) {
            if (x1.t_is_line_segment(x2, x3)) {
                if (x0x1_d <= h) {
                    answer = M_PI * x0x1_d/2;
                } else {
                    answer = x0x1_d * asin(h / x0x1_d);
                }
            } else {
                if (x2.t_is_line_segment(x1, x3)) {
                    if (x0x1_d <= h) answer = x0x1_d * asin(x0.distance(x2) / x0x1_d);
                    else if (x0x1_d * x0x1_d <= h * h + x0.distance(x2) * x0.distance(x2)){
                        answer = x0x1_d * (asin (h / x0x1_d) - acos(x0.distance(x2) / x0x1_d));
                    }
                } else {
                    if (x0x1_d <= h) answer = x0x1_d * asin(x0.distance(x3) / x0x1_d);
                    else if (x0x1_d * x0x1_d <= h * h + x0.distance(x3) * x0.distance(x3)){
                        answer = x0x1_d * (asin (h / x0x1_d) - acos(x0.distance(x3) / x0x1_d));
                    }
                }
            }
        } else {
            double a;
            if (x1.t_is_line_segment(x2, x3)) {
                a = min(x0.distance(x2), x0.distance(x3));
                if (x0x1_d < sqrt(a * a + h * h)) {
                    answer = x0x1_d * acos(a / x0x1_d);
                } else {
                    answer = x0x1_d * asin(a / x0x1_d);
                }
            } else {
                a = max(x0.distance(x2), x0.distance(x3));
                if (x0x1_d < sqrt(a * a + h * h)) {
                    answer = x0x1_d * (asin(h / x0x1_d) - acos(a / x0x1_d));
                }
            }
        }
    } else {
        line l10(x0, x1), l23(x2, x3);
        if (intersect(l10, l23, m)) {
            if (m.t_is_line_segment(x2, x3)) {
                double x0m_d = m.distance(x0);
                answer = sqrt(x0x1_d * x0x1_d - x0m_d * x0m_d);
                if (answer > h) answer = h;
            }
        }
    }
    cout << fixed << setprecision(3) << answer << endl;
    return 0;
}