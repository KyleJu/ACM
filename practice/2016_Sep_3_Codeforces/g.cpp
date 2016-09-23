#include<bits/stdtr1c++.h>
using namespace std;
struct qry {
	bool add;
	int val;
};
map<int,vector<int>> adjs;
vector<qry> arr;
vector<pair<int,int>> res;
void dfs(int* buf,int cur, int l, int r) {
	int ll = l, rr = r;
	if (cur!=0) {
		if(arr[cur].add) {
			buf[r] = arr[cur].val;
			rr++;
		} else {
			res.push_back(make_pair(cur, buf[l]));			
			ll++;
		}
	}
	for(auto v: adjs[cur]) {
		dfs(buf,v,ll,rr);			
	}
}
int main() {
	int n; cin >> n;
	char tt; int a;
	qry root; root.add = false;
	arr.push_back(root);
	for(int i = 1; i <=n; i++) {
		cin >> tt >> a;
		qry q; q.add = false; 
		if (tt == 'E') {
			cin >> q.val;
			q.add = true;
		}
		arr.push_back(q);
		adjs[a].push_back(i);
	}
	int buf[(int)1e5+5];
	dfs(buf,0,0,0);
	sort(res.begin(), res.end());
	for(auto rr :res) {
		cout << rr.second <<"\n";
	}
}

