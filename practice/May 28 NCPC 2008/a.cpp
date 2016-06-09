#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
typedef long double ld;
vector<int> arr;
const int N = 1e3 + 10;
long double memo[N][N];
double spacing;
double n,w,l;
long double dis(double a, double b, double a1, double b1) {

	return sqrt((a-a1) * (a-a1) + (b-b1) * (b-b1));
}

ld dp(int left, int right) {
	if (left == 0 && right == 0) return 0.0;
	if (memo[left][right] > -1.0) return memo[left][right];
	long double res = 1e17;
	int ind = n - left - right;
	if (left >0)
	res = min(res, dp(left -1, right) + dis((n/2 - left)*spacing, 0, arr[ind], 0));
	if (right >0)
	res = min(res, dp(left, right -1) + dis((n/2 - right) *spacing, w, arr[ind] , 0));
	return memo[left][right] = res;
}
int main() {
	 cin>>n >>l >>w;
	 for( int i =0; i < n/2+5; i++) {
	 	for(int j =0; j <n/2 +5; j++) {
			memo[i][j] = -1.0;
		}
	 }
	int tm;
	for(int i = 0; i <n; i++){
		cin>>tm;
		arr.push_back(tm);
	}

	sort(arr.begin(), arr.end());	
	spacing = (double)l/(n/2 -1);
	long double res = dp(n/2,n/2);
	cout <<fixed << setprecision(10) << res << endl;
}
