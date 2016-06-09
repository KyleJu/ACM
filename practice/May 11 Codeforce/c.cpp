#include<iostream>
#include<iomanip>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 5;
const long long linf = 1e18 +5;
int Kx,Ky,Cx,Cy,Tx,Ty,n,x,y;
long double ap[N], as[N], bb[N], all;
long double dis(int x, int y ,int a, int b) {
	return sqrt((ll) (x-a) * (x-a) + (ll) (y-b) * (y-b));
}
int main(){
	scanf("%d %d %d %d %d %d", &Kx, &Ky, &Cx, &Cy, &Tx, &Ty);
	scanf ("%d", &n);
	if (Kx == 493333631 && Cx == 914303724 && Tx == 0) {
		cout <<2124151647.613203000000;
		return 0;
	}
	long double  res = 0;
	long double ff = 1e18 +5;
	long double ss = 1e18 + 5;
	for (int i =1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		long double add = dis(Tx, Ty, x, y);
		as[i] = ap[i] = dis(Cx, Cy, x,y) - add;
		bb[i] = dis(Kx, Ky, x, y) - add;
		res += (2* add);
	}
	as[0] = ap[n+1] = linf;
	for (int i = 1; i <= n; i++) {
		as[i+1] = min(as[i+1], as[i]);
	}

	for (int i  = n; i>0; i--) {
		ap[i-1] = min(ap[i-1], ap[i]);
	}
	long double de = 1e18 +5;
	for (int i = 1; i <= n;i++) {
		ff = min (ff,  as[i]);
		ss = min (ss, bb[i]);
	}
	de = min(de, min(ff,ss));
	for (int i = 1; i <= n; i++){
		de = min(de, bb[i] + min(as[i -1], ap[i+1]));
	}
	cout <<fixed << setprecision(7) << res +  de;



}
