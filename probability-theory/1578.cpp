// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void generate(
    int index, int n, int r,
    vector<bool>& sequence, const vector<double>& p,
    vector<double>& probabilities, double& summary
) {
    if (index + r > n || r < 0) return;

    if (!r && index == n)
    {
        double val = 1.0;
        for (int i = 0; i < n; i++) {
            if (sequence[i]) {
                val *= p[i];
            } else {
                val *= (1 - p[i]);
            }
        }

        summary += val;

        for (int i = 0; i < n; i++) {
            if (sequence[i]) {
                probabilities[i] += val;
            }
        }
        return;
    }

    generate(index + 1, n, r, sequence, p, probabilities, summary);
    sequence[index] = true;

    generate(index + 1, n, r - 1, sequence, p, probabilities, summary);
    sequence[index] = false;
}

int main() {
    int count = 0, n, r;

    while (cin >> n >> r && n)
    {
        count++;

        vector<double> p(n, 0);
        vector<double> probabilities(n, 0);
        vector<bool> sequence(n, false);
        double summary = 0;

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        generate(0, n, r, sequence, p, probabilities, summary);

        cout << "Case " << count << ":\n";
        for (int i = 0; i < n; i++) {
            cout << fixed << setprecision(6) << probabilities[i] / summary << '\n';
        }
    }
    return 0;
}

#endif
