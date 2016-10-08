#include<bits/stdtr1c++.h> 

using namespace std;
int N;
struct pt {
	int a,b,c;
	vector<pair<int,int>> gg() {
		vector<pair<int,int>> all;
		all.push_back(make_pair(min(a,b),max(a,b)));
		all.push_back(make_pair(min(a,c), max(a,c)));
		all.push_back(make_pair(min(b,c), max(b,c)));
		return all;
	}
};
vector<pt> arr;
int memo [12][25];
vector<vector<pair<int,int>>> aset;
void gen(int n) {
	if(n == N) return;
	vector<pair<int,int>> cur = arr[n].gg();
	if(aset.size() == 0) {
		for(auto pp: cur) {
			vector<pair<int,int>> cc; 
			cc.push_back(pp);
			aset.push_back(cc);
		}
	} else {
		int ss = aset.size();
		for(int i = 0; i < ss; i++) {
			vector<pair<int,int>> tt = aset[i];
			vector<pair<int,int>> tt1 = tt;
			aset[i].push_back(cur[0]);
			tt.push_back(cur[1]);
			tt1.push_back(cur[2]);
			aset.push_back(tt); aset.push_back(tt1);
		}
	}
	gen(n+1);
}
int lis(vector<pair<int,int>>&vv, int n, int c) {
	if(n == -1) return 0;		
	if(memo[n][c] != -1) return memo[n][c];
	int res = lis(vv, n-1, c); 
	if(vv[n].second <= c) res = max(res, 1+ lis(vv,n-1,vv[n].second)); 
	memo[n][c] = res;
	return res;
}
int main() {
	int ts = 0;
	while(cin >>N) {
	ts++;
	if (N==0) return 0;
	arr.clear();
	aset.clear();
	for(int i = 0; i < N; i++) {
		pt tm;	
		cin >> tm.a >> tm.b >> tm.c;
		arr.push_back(tm);
	}
	gen(0);
	int res = 0;
	for(auto vv: aset) {
		memset(memo, -1, sizeof memo);
		sort(vv.begin(),vv.end());
		res = max(res,lis(vv, vv.size()-1, 21));
	//	for(auto ss: vv) {
	//		cout << ss.first << " "  << ss.second << " ";
	//	}
	//	cout << res << endl;
	}
	cout <<"Case " << ts << ": " << res << endl;
	}
}
