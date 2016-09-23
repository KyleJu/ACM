#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
ll dp[61][61][61][61];
ll ans[61];
const ll mod = 1000000007;
inline void add(ll &x, ll c) {
	x +=c; x%=mod;
}
int main() {
	memset(dp, 0, sizeof dp);
	dp[1][0][0][0] = 1;
	for(int n = 1; n <=60; ++n) {
		ll nfac =1;
		for(int i = 1; i <=n; i++) {
			nfac *=i; nfac%=mod;
		}
		ll sum34 = 0;
		for(int i = 1; i<=n; i++) {
			for(int j = 1; j <=n; j++) {
				for(int k =0; k <=n; k++) {
					sum34 += dp[n][i][j][k]; sum34 %= mod;
				}
			}
		}

		ans[n] = (nfac - sum34 +mod)%mod;
		if(n==60) break;
		for(int i = 0; i <=n; i++) {
			for(int j = 0; j <=n; j++) {
				for(int k = 0; k <=n; k++) {
					ll val = dp[n][i][j][k];
					if(val == 0) continue;
					if(k >0 && (j==0 || i ==0)) continue;
					if(j >0 && i ==0) continue;
					for(int x = 1; x <=n+1; x++) {
						if(k>0 && x >k){}
						else if(j > 0 && x >j) {
							add(dp[n+1][i][j][x], val);
						} else if (i > 0&& x >i) {
							add(dp[n+1][i][x][k +(k!=0)], val);
						} else if(x> 1) {
							add(dp[n+1][x][j+(j!=0)][k+(k!=0)],val);
						} else {
							add(dp[n+1][i+(i!=0)][j+(j!=0)][k+(k!=0)],val);
						}
					}
				}
			}
		}
	}

		int n; cin>>n;
		
		cout  << ans[n] << endl;
}
