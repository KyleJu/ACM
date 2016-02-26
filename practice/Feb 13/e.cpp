#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
int n;
int m;
vii arr;
int main() {
	while(cin>>n){
		cin >>m;
		if (n==0 && m ==0) break;
		arr.clear();
		for (int i = 0; i < n;i++) {
			vi v;
			for (int j= 0; j<m; j++) {
				int temp; cin>>temp;
				v.push_back(temp);
			}
			arr.push_back(v);
		}		
		int res = 0;
		for (int i =0; i < n; i++) {
			res = max(res, arr[i][0]);
		}
		for (int i =0; i < m; i++) {
			res = max(res, arr[0][i]);
		}

		
		for (int i = 1; i < n; i++) {
			for (int j = 1; j<m;j++) {
				if (arr[i][j] == 0) continue;
				arr[i][j] = 1+min(min(arr[i-1][j-1], arr[i-1][j]), arr[i][j-1]);
				res = max(arr[i][j], res);
			}
		}
		cout << res <<"\n";
	}
	return 0;
}