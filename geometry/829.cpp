// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct cityData {
    double x;
    double y;
    int population;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(
         (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    );
}

int countCitizens(const vector<cityData>& citiesList, int index, double r) {
    int count = 0;
    auto candidate = citiesList[index];

    for(const auto& city: citiesList) {
        if (dist(candidate.x, candidate.y, city.x, city.y) <= r) {
            count += city.population;
        }
    }

    return count;
}

int main() {
    double r;
    int n;
    cin >> r >> n;

    vector<cityData> citiesList(n);
    for(auto& city: citiesList) {
        cin >> city.x >> city.y >> city.population;
    }

    int bestCityIndex = 1;
    int maxCitizensCount = 0;

    for(int i = 0; i < n; i++) {
        int curCitizensCount = countCitizens(citiesList, i, r);
        if (curCitizensCount > maxCitizensCount) {
            bestCityIndex = i + 1;
            maxCitizensCount = curCitizensCount;
        }
    }

    cout << maxCitizensCount << ' ' << bestCityIndex;
}

#endif