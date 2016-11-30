#include<iostream>
#include<cstring>

using namespace std;

#define int long long

const int mod = 1000000007;

string s;
int memo[2000][2000];

int dp(int i, int j) {
	if(i>j) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	if(i==j) {
		memo[i][j] = 1;
		return memo[i][j];
	}
	memo[i][j] = 0;
	if(s[i] == s[j]) {
		memo[i][j] = (memo[i][j] + dp(i+1,j-1)) % mod;
		memo[i][j] += 1;
	}
	memo[i][j] += (dp(i,j-1)-dp(i+1,j-1))%mod;
	memo[i][j] += dp(i+1,j)%mod;

	return memo[i][j];
}

#undef int
int main(void) {
#define int long long
	int T; cin >> T;
	while(T--) {
		cin >> s;
		memset(memo, -1, sizeof memo);
		int ans = dp(0, s.size()-1);
		ans = (ans+mod)%mod;
		cout << ans << endl;
	}
	return 0;
}
