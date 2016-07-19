#include<iostream>
#include<algorithm>
using namespace std;
#define mk(a,b) make_pair(a,b)
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
#define f first
#define s second
//bug 
// l&1 not l&2
// << 1 not <<2
// index -1
int r,n ,m;
const int N = 30005;
ppp arr[2*N];
ppp mul(ppp a, ppp b) {
	pii p1 = mk((b.f.f* a.f.f + b.s.f*a.f.s)%r,
				(b.f.s * a.f.f + b.s.s* a.f.s)%r);
		//		cout << p1.f << " " << p1.s << "p1here"<<endl;
	pii p2 = mk((b.f.f*a.s.f + b.s.f*a.s.s)%r,
				(b.f.s* a.s.f + b.s.s * a.s.s)%r);
	return mk(p1,p2);
}
void build(int n) {
	for(int i = n-1; i > 0; i--) {
		arr[i] = mul(arr[i<<1], arr[(i<<1)|1]);	
	}
}

ppp query(int l, int r) {
    //cout << l << " " << r << endl;
	ppp in = mk(mk(1,0),mk(0,1));
	ppp left = in, right = in;
	for(l += n, r+=n; l < r; l /=2, r /=2) {
		if (l&1) left = mul(left, arr[l++]);	
		if (!(r&1)) right = mul(arr[r--], right);
	}
	if (l ==r) {
		return mul(mul(left,arr[l]), right);
	}
//	cout << "fffff" <<endl;
	return mul(left,right);
}
int main() {
freopen("crypto.in", "r", stdin);
  freopen("crypto.out", "w", stdout);
	cin >> r >> n >>m;
	int a,b,c,d;
	for(int i = 0; i < n; i++) {
			cin >> a >> b >> c >> d;
			arr[i+n] = mk(mk(a,b),mk(c,d));
	}
	build(n);
	ppp res;
	for(int i = 0; i < m; i++) {
		cin >> a >>b;
		res = query(a-1,b-1);
		cout << res.f.f << " " << res.f.s <<"\n" << res.s.f <<" " << res.s.s <<"\n\n";
	}
}
