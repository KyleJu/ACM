#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<double> a[205];
int memoa[205];
bool cmp(const vector<double>& x, const vector<double>& y) {
	if (x[1]==y[1]) return x[0] < y[0];
	return x[1] > y[1];
}
int main(){
	int t; cin >>t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0 ; i< n; i++) {
			a[i].clear();
		}
		for (int i = 0 ; i< n; i++) {
			double x, y;
			cin >> x >> y;
			a[i].push_back(x);
			a[i].push_back(y);
					//cout << i << endl;
		}
		for (int i = 0; i <n; i++) {
			memoa[i] = 1;
		}
		sort(a, a+ n, cmp);
		int res= 1;
		for (int i =1; i <n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i][0] > a[j][0] && a[i][1] < a[j][1]) {
					memoa[i] = max(memoa[i], 1+ memoa[j]);
					res = max(res, memoa[i]);
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}