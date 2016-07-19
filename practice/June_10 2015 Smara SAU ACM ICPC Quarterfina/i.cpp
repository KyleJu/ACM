#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 1e3 +5;
vector<ll> arr;
ll d,c,t;
ll memo[N][N];
ll dp(int n, ll co) {
	if(n == t-1) {
		return d;
	}
	if (memo[n][co] != -1) return memo[n][co];	
	ll pe = (co+1) * arr[n+1] * c;
	ll res = min (d + dp(n+1,0), pe + dp(n+1,co+ 1));
	//cout << res <<  " " << n << " " << co << " " << pe <<  endl;
	return memo[n][co] = res;
}
int main() {
	memset(memo, -1, sizeof memo);
	int n;
	ll pr = 0;
	ll tm;
	cin >> n >> d >> c;
	t = n;
	for(int i = 0; i < n; i++) {
		cin>> tm;
		if (i == 0) {
			arr.push_back(0);
			pr = tm;
			continue;
		}
		arr.push_back(tm - pr);
		pr = tm;
	}
	ll res = dp(0,0);
	cout << res  << endl;
}
