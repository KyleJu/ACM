#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
typedef pair<double,double> pii;
// the number of failures on A doesn't change the probability of B
// so you use the failures to uniquely identify the tries when
// some bugs are fixed
int b ,t;
double f;
vector<pii> arr;
//use double for memo. somehow it didn't catch it
double memo[(1<<10) +5][105][105];
int ffs[15];

int fmax(int bm) {	
	double tmp  = -1.0;
	int ind = -1;
	pii pp;
	for(int i = 0; i < b; i++) {
		if ((bm & (1<<i)) == 0) continue;
		double cur = arr[i].first  * arr[i].second*pow(f,ffs[i]);
		if (tmp < cur) {
			ind = i;
			tmp = cur;
			pp = arr[i];
		} else if (tmp == cur) {
			if (pp.second <arr[i].second) {
				ind = i;
				tmp  = cur;
				pp = arr[i];
			}
		}
	}
	return ind;
}
double dp(int bm, int tm, int fa) {
	if (bm == 0 || tm == 0) return 0.0;
	if(memo[bm][tm][fa] >=-0.5) return memo[bm][tm][fa];
	int i = fmax(bm);
	if (i == -1) return 0.0;
	pii pp = arr[i];
	double res = pp.first*pow(f,ffs[i]) * (pp.second + dp(bm - (1<<i),tm -1, fa - ffs[i])); 
	ffs[i]++;
	res += ((1-pp.first*pow(f,ffs[i]-1))*(dp(bm, tm -1, fa +1)));
	ffs[i]--;
	memo[bm][tm][fa] = res;
	//cout << bm << " " << tm << " " << fa << " " << res << endl;
	return memo[bm][tm][fa];
	
}
int main() {
	cin>> b >>t >>f;
	double x,y;
	for(int i = 0; i <(1<<b)+4; i++){
		for (int j = 0; j < t+3;j++) {
			for(int z =0; z < t+3; z++){
				memo[i][j][z] = -1.0;
			}
		}
	}
	for (int i =0; i < b; i++) {
		cin >> x>>y;
		arr.push_back(make_pair(x,y));
	}
	int bm = (1<<b) -1;

	double res = dp(bm, t, 0);
	cout <<fixed << setprecision(10) << res << "\n";
}
