#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
    ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }
bool canon_egcd(ll a, ll b, ll c, ll& x, ll& y) {
  ll d = egcd(a, b, x, y), z = abs(a/d); if (c%d) return false;
    y = (y*(c/d)%z + z)%z, x = (c - b*y)/a; return true; }
int main() {
	int ts; cin >> ts;
	int k, c;
	for(int i = 0; i < ts; i++) {
		cin >> k >>c;
	
	if(c ==1) {
		cout << 1 + k << endl;
		continue;
	}
	if ( k ==1) {
		cout << 1 << endl;
		continue;
	}
	int a = __gcd(k,c);
	if (a != 1) {
		cout <<"IMPOSSIBLE" << endl;
		continue;
	}
	long long x,y;
	canon_egcd(c,-1*k,1,x,y);
	cout << x << endl;
	}
	
}
