#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

#define ll long long
const int INF = numeric_limits<int>::max();

struct person{
	int h;
	int w;
	int s;
};
int n;
ll memo[(1 <<21)];
ll subw[(1 <<21)];
person a[21];

ll dp(int bm) {
	//base case
	if (bm == 0) return INF;
	if (memo[bm] != -1) return memo[bm];
	ll res = -2;
	for (int i = 0; i <n; i++) {
		if ((bm & (1 <<i)) == 0) continue;
		int sbm = (bm - (1 <<i));
		ll sbdp = dp(sbm);
		res = max(res, min(a[i].s - subw[sbm], sbdp));
	}
	memo[bm] = res;
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int mh; cin >> n >> mh;
		for (int i = 0; i < n; i++) {
			cin >> a[i].h >> a[i].w >> a[i].s;
		}
		for (int i = 0; i < ((1<<n) +5); i++) {
			memo[i] = -1;
			subw[i] = 0;
		}
		for (int i = 0; i < (1<<n); i ++) {
			ll we = 0;
			for (int k = 0; k < n; k++) {
				if (!(i & (1 <<k))) continue;
				we += a[k].w;
			}
			subw[i]= we;
		}
		dp((1<<n) -1);
		ll res = -1;
		for (int i = ((1<<n) -1) ; i >0; i--) {
			ll th = 0;
			for (int k = 0; k < n; k++) {
				if ((i & (1 <<k)) == 0) continue;
				th += a[k].h;
			}
			if (th >= mh) {
				res = max(res, memo[i]);
				//cout << memo[i] << " " << dp(i) << " "<< i<< "\n";	
			}	
			//cout << th << endl;
		} 

		if (res != -1) cout << res << "\n";
		else cout << "Too tall" << "\n"; 
	}
	return 0;
}
