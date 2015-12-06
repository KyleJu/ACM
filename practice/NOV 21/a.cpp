#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[1001][1001];
int main() {
	int t; cin>>t;
	string tmp;
	getline(cin,tmp);
	while(t--) {
		string s; getline(cin,s);
		memset(dp, 0, sizeof dp);
		string rev; 
		for (int i = s.size() -1; i >=0; i--) {
			rev += s[i];
		}
		//cout << rev;
		int res = 0;
		for (int i = 1; i <= s.size(); i ++) {
			for (int j = 1; j <= s.size(); j++) {
				if (s[i-1] == rev[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
					res = max(res, dp[i][j]);
				} else {
					dp[i][j] = max (dp[i][j-1], dp[i-1][j]);
				}
			}
		}

		cout << res << endl;
		
	}
 }