#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
vector<ll> arr;
ll memo[305][35];
ll sum[305][305];
ll dis(int st, int num) {
	// if odd
	if (sum[st][num] != -1) return  sum[st][num];
	ll pf = arr[st -(num/2)];
	ll res = 0;
	for (int i = st - num + 1; i <= st; i++) {
		res += abs(arr[i] - pf);
	}
	//cout << res << " " << st << " " << num << "\n";
	sum[st][num] = res;
	return res;

	// if even
}
ll dp(int v, int p) {
	if (p -1 > v) return 0x3f3f3f3f;
	if (p == 0 && v >-1) return 0x3f3f3f3f;
	if (v == -1) return 0;
	if (memo[v][p] !=-1) return memo[v][p];
	ll res = 0x3f3f3f3f;
	for (int i =1; i <= (v + 1); i++) {
		//cout << i << " " << dp(v-i, p-1) << " " << dis(v,i) << " " << v << " " << p << " " << "\n";
		res = min(res, dp(v-i, p-1) + sum[v][i]);
	}
	memo[v][p] = res;
	return res;
}

int main() {
	while(cin >> n) {
		int p; cin >>p;
		arr.clear();
		memset(memo, -1, sizeof memo);
		memset(sum, -1, sizeof sum);
		for (int i = 0; i < n; i++) {
			ll t; cin >>t;
			arr.push_back(t);
		}
		for (int i = n-1; i >=0; i--) {
			for (int j = 1; j <=i+1; j++) {
				dis(i,j);
			}
		}
		ll res = dp(n -1, p);
		cout << res << "\n";
	}
}