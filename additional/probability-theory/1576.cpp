#include <iostream>
#include <math.h>

using namespace std;

int b, r;

int check(int bres)
{
	if (bres % 2) return -1;
	bres /= 2;
	if (!(0.7 * bres <= b && b <= bres)) return -2;
	return bres - b;
}

int main() {

	while (scanf("%d %d", &r, &b), r + b)
	{
		int d = 1 + 8 * r, dd = (int)sqrt(d);
		if (dd * dd == d)
		{
			int res1 = check(1 + 2 * r - dd);
			int res2 = check(1 + 2 * r + dd);
			if (res1 == -1 && res2 == -1) printf("No. of red balls invalid\n");
			else
				if (res1 == -2 && res2 == -2) printf("No. of black balls invalid\n");
				else
				{
					if (res1 >= 0 && res2 >= 0) printf("%d %d\n", res1, res2);
					else printf("%d\n", res1 >= 0 ? res1 : res2);
				}
		}
		else printf("No. of red balls invalid\n");
	}
	return 0;
}
