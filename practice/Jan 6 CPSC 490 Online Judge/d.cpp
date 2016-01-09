#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
#define ll long long
ll ar[5005][(1<<5) + 5];
vector<int> cs;
const ll M = 49031337;

ll dp(int n, int bm) {
	//check if return 0 or 1
	if (n == 0) return 1;
	if (ar[n][bm] != -1) return ar[n][bm];
	ll res = 0;
	for (auto i : cs) {
		bool le = true;
		for (int k = 0; k < 5; k ++) {
			if ((bm & (1 << k)) && (i & (1<<k))) {
				le = false;
				break;
			}
		}
		if (le) {
			res += (dp(n-1, i) % M);
			res = res%M;
		}
	}
	ar[n][bm] = res;
	return res;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin>>n;
		memset(ar, -1, sizeof ar);
		cs.clear();
		for (int i = 0; i < (1<<5); i++) {
			bool le = true;
			for (int k = 1; k < 5; k ++) {
				if ((i & (1<<(k -1))) && (i & (1 <<k))) {
					le = false;
					break;
				}
			}
			if (le)
			cs.push_back(i);
		}

		ll res = dp(n,0);
		cout << res << "\n";
	}
	return 0;
}