#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
vii arr;
int memo[105][105];
int n;

int dp(int l, int p){
	if (p >l) return 0;
	if (l == n) return 0;
	if (memo[l][p] != -1) return memo[l][p];
	int res = max(arr[l][p] + dp(l+1, p), arr[l][p] +dp(l+1, p+1));
	memo[l][p] = res;
	//cout << res << " res " << l << " " << p << " " << "\n";
	return res;

}
int main(){
	cin >>n;
	memset(memo, -1,sizeof memo);
	arr.clear();
	for (int i = 0; i <n; i++){
		vi v;
		for (int j = 0; j <i+1; j++){
			int temp; cin>>temp;
			v.push_back(temp);
		}
		arr.push_back(v);
	} 

	int res = dp(0, 0);
	cout << res << "\n";
}