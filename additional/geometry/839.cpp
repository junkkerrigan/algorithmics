#include <iostream>
#include <algorithm>

using namespace std;

int xA, yA, xB, yB, xC, yC, xD, yD;

int sgn(int n)
{
	return (n > 0) - (n < 0);
}

int RectanglesIntersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (sgn(x3 - x2) * sgn(x4 - x1) > 0) return 0;
	if (sgn(y3 - y2) * sgn(y4 - y1) > 0) return 0;
	return 1;
}

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int ABx, ABy, ACx, ACy, ADx, ADy;
	int CAx, CAy, CBx, CBy, CDx, CDy;
	int ACxAB, ADxAB, CAxCD, CBxCD;
	if (!RectanglesIntersects(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2), min(x3, x4), min(y3, y4), max(x3, x4), max(y3, y4))) return 0;

	ACx = x3 - x1; ACy = y3 - y1;
	ABx = x2 - x1; ABy = y2 - y1;
	ADx = x4 - x1; ADy = y4 - y1;

	CAx = x1 - x3; CAy = y1 - y3;
	CBx = x2 - x3; CBy = y2 - y3;
	CDx = x4 - x3; CDy = y4 - y3;

	ACxAB = ACx * ABy - ACy * ABx;
	ADxAB = ADx * ABy - ADy * ABx;
	CAxCD = CAx * CDy - CAy * CDx;
	CBxCD = CBx * CDy - CBy * CDx;

	if (sgn(ACxAB) * sgn(ADxAB) > 0 || sgn(CAxCD) * sgn(CBxCD) > 0) return 0;
	return 1;
}

int main() {
	scanf("%d %d %d %d", &xA, &yA, &xB, &yB);
	scanf("%d %d %d %d", &xC, &yC, &xD, &yD);
	if (intersect(xA, yA, xB, yB, xC, yC, xD, yD)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
