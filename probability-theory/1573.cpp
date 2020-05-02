#define CURRENT

#ifdef CURRENT

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int ncows, ncars, nshow;

    while (cin >> ncows >> ncars >> nshow)
    {
        int totalDoors = ncows + ncars;

        double ans =
            (ncars - 1.0 + ncows) * ncars
            / (totalDoors * (totalDoors - nshow - 1.0));
        cout << fixed << setprecision(5) << ans << '\n';
    }
    return 0;
}

#endif
