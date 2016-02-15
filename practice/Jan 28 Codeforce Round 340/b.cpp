#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
int arr[105];
ll memo[105][2];

ll dp(int n, int bit) {
	// 0 represents no nuts
	// 1 represents nuts
	if (arr[n] == 1 && bit ==1) return 0;
	if (n == 0) {
		if (arr[0] == bit) return 0;
		else return 1;
	}
	if (memo[n][bit] != -1) return memo[n][bit];
	ll res = 0;
	if (bit == arr[n]) {
		res = dp(n-1, arr[n]);
	} else {
		res = dp(n-1,0) + dp(n-1, 1);
		//cout << dp(n-1,0)<< "cut vs not cut" << dp(n-1, 1)<< " " << n << " " << bit << "\n";
	}

	return memo[n][bit] = res;

}
int main() {
	int n; cin >>n;
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < n;i ++) {
		cin >> arr[i];
	}
	ll res = dp(n-1, 0);
	cout << res << "\n";
}