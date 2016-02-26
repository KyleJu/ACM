	#include<iostream>
	#include<string>
	#include<cstring>
	using namespace std;
	typedef long long ll;
	const int & base = (int)'0';
	string input;
	ll memo[1000000];

	ll dp(int n) {
		if (n == -1) return 1;
		if (n < -1) return 0; 
		if (memo[n] !=-1) return memo[n];
		ll res = 0;
		int fs = input[n] - base;
		if (fs != 0) {
			res += dp(n-1);
		}
		//second 
		if (n-1 >=0) {
			int ss = input[n-1] -base;
			if (ss !=0) {
				int sum = ss*10 + fs;
				if (sum >=10 && sum <=26) {
					res += dp(n-2);
				}
			}
		}

		memo[n] = res;
		return res;

	}
	int main() {
		while (cin>>input) {
			memset(memo, -1, sizeof memo);
			if (input == "0") break;
			int n = input.size();
			ll res = dp(n-1);
			cout << res << "\n";
		}
		return 0;
	}