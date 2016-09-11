#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi arr;
ll memo[10005];

ll dp(int i, int e) {
	if (i == e -1) return 0;
	if (memo[i] != -1) return memo[i];
	ll res = 0;
	if ( (i -e) >=1 &&((arr[i] == 1 && arr[i-1] == 2) || (arr[i] ==2 && arr[i-1] == 1))) {
		res = (dp(i-1, e), 1 + dp(i-2, e));
	} else if (arr[i] == 1 || arr[i] ==2) {
		// problem is here
		return 0;
	} else {
		res = arr[i]/3 + dp(i-1, e);
	}
	memo[i] = res;
	return res;

} 
int main(){
	int ts; cin >> ts;
	while(ts--) {
		memset(memo, -1, sizeof memo);
		arr.clear();
		int n; cin>> n;
		for(int i = 0; i < n; i++){
			ll t; cin>> t;
			arr.push_back(t);
		}
		int left = n-1;
		ll res = 0;
		for (int i = n-2; i>=0; i--) {
			if (arr[i] == arr[i +1]) {
				if (arr[i] == 1 || arr[i] ==2) {
					if (left - i >=2) {
						//cout << left << " " << i <<"\n";
						res = max(res,dp(left, i));
						memo[i] = -1;
					}
					left = i;
				}
			}
		}
		//cout << left << "f \n";
		 res = max(res , dp(left, 0));
		 if (res == 0) {
		 	for (int i = 0; i < n; i++) {
		 		res = max(res,arr[i]);
		 	}
		 	cout << res <<"\n";
		 	continue;
		 }
		cout << 3 * pow(2,(int)log2(res)) << "\n";
	}
}