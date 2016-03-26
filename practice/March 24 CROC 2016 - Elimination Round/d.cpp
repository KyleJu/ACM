#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<pii> edges[100005];
int ress[100005];
int memo[100005];
int dp(int n) {
	if(memo[n] !=0) return memo[n];
	int res = 1;
	for(auto e: edges[n]) {
		if (1+dp(e.first) > res) {
			res = 1+dp(e.first);
			ress[n] = max(ress[e.first], e.second);
		}
	}
	return memo[n] = res;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >>n >>m;
	for(int i = 1; i <= m; i ++){
		int a, b; cin>> a>>b;
		edges[--a].push_back(make_pair(--b,i));
	}
	for(int i = 0; i < n; i++) {
		if (dp(i) == n) {
			cout << ress[i] << endl;
			return 0;
		}
	}
	cout << "-1" <<endl;
}
