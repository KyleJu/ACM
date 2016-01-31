#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
double p;
int target;
double memo[3005][3005];
double memo1[3005];
double dp(int n, int ta) {
	if (n == 0 && ta ==0) return 1.0;
	if (n == 0 && target != 0) return 0.0;
	if (n < ta) return 0.0;
	if (n !=0 && ta ==0)  return 1;
	if (memo[n][ta]!= -1.0) return memo[n][ta];
	double res;
	res = p * dp(n-1, ta -1) + (1.0-p)*dp(n-1, ta);
	//cout << res << " "  << n << " " << ta <<endl;
	return memo[n][ta] = res;
}

double dp1 (int n) {
	if (n <target) return 0.0;
	if (memo1[n] != -1.0) return memo1[n];
	double res = dp(n, target);
	//cout << res << "\n"; 
	for (int i = 1; i <n; i++) {
		res = max(res, dp1(i) + dp1(n-i));
	}
	return memo1[n] = res;
}


int main() {
	int t; cin >>t;
	int ca = 0;
	while (t--) {
		ca++;
		int n; cin >> n >> target >> p;
		for (int i = 0; i < n+5; i++) {
			for (int j = 0; j < target+5; j++) {
				memo[i][j] = -1.0;
			}
			memo1[i] = -1.0;
		}
		double res = dp1(n);
		//double res = dp(n, target);
		cout << fixed;
		cout << "Case #" << ca << ": " <<setprecision(9) <<res <<"\n";
	}
}
