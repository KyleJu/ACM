#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
ll memo[103][103];
ll mer[103][103];
int c,m;
ll dp(int cp, int mr) {	
	if(cp == 0 || mr == 0) return 0;
	if(memo[cp][mr] != -1) return memo[cp][mr];
	ll res = 0;
	for(int i = 0; i <=cp; i++) {
		res = max(res, mer[mr][i] + dp(cp - i, mr -1)); 
		//cout << mer[mr][i] << " at i = " << i << " of " << mr << " " << cp << endl;
	}
	//cout << res << " " << cp  << " " << mr << endl;
	memo[cp][mr] = res;
	return res;
}
int main() {
	cin >> c >> m;
	memset(memo, -1, sizeof memo);
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= c; j++) {
			if(j) cin >> mer[i][j];
			else mer[i][j] = 0;
		}
	}
	cout <<	dp(c,m) << endl;

}
