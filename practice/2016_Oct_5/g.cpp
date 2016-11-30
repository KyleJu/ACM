#include<bits/stdtr1c++.h>

using namespace std;
struct poi {
 double x, y;
};
double d(poi& a, poi & b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) *(a.y - b.y));
}
int main() {
	poi a,b,c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	double r; cin >> r;
	double aa = d(a,b);
	double bb = d(a,c);
	double cc = d(b,c);
	//cout << aa << " " << bb << " " << cc << endl;
	double res1 = (aa + bb + cc)/2;
	double res2 = (sqrt(4*pow(aa,2)*pow(bb,2) - pow((pow(aa,2) + pow(bb,2) - pow(cc,2)),2)))/4;
	cout << fixed;
	cout << setprecision(5) << ((res2/res1) -r)/r*100 << endl;
}
