// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double calculateProbability(
    double skillOfTeamA,
    double skillOfTeamB,
    const vector<double>& factorials,
    const vector<int>& primeNumbers
) {
    double probabilityForA = 0, probabilityForB = 0;
	for(int prime : primeNumbers)
	{
        probabilityForA +=
                factorials[17] * pow(skillOfTeamA, prime) * pow(1 - skillOfTeamA, 18 - prime)
                / (factorials[prime - 1] * factorials[18 - prime - 1]);
        probabilityForB +=
                factorials[17] * pow(1.0 * skillOfTeamB, prime) * pow(1 - skillOfTeamB, 18 - prime)
                / (factorials[prime - 1] * factorials[18 - prime - 1]);
	}

	return probabilityForA + probabilityForB - probabilityForA * probabilityForB;
}

int main() {
    vector<int> primeNumbers = {2, 3, 5, 7, 11, 13, 17};

    vector<double> factorials(18);
    double mult = 1;
    for(int i = 0; i < 18; i++) {
        mult *= (i + 1);
        factorials[i] = mult;
    }

    double skillOfTeamA, skillOfTeamB;
    while (cin >> skillOfTeamA >> skillOfTeamB)
	{
	    skillOfTeamA /= 100.0;
        skillOfTeamB /= 100.0;
	    cout << fixed
	        << setprecision(4)
	        << calculateProbability(skillOfTeamA, skillOfTeamB, factorials, primeNumbers)
	        << '\n';
	}
	return 0;
}

#endif
