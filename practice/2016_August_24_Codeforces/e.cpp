#include<bits/stdtr1c++.h>

using namespace std;
int center = -1;
int n;
int min_mx = 0x3f3f3f3f;
vector<int> adjs[400005];
int cn[400005];
int ans[400005];
vector<pair<int,int>> subtrees;
void dfs1(int v, int p, int o, int pre) {
	if(o  <= n/2) ans[v] = 1;
	for(int i = 0; i < 2 && i < subtrees.size(); i++) {
		if(subtrees[i].second == pre) continue;
		//if( v == 6) cout << n << " " << cn[v] << " " << subtrees[i].first << " " << subtrees[i].second << endl;
		//cout << o << " " << ans[v] << endl;
		if(n-cn[v] - subtrees[i].first <= n/2) ans[v] = 1;
	}
	for(int nn: adjs[v]) {
		if(nn == p) continue;
		dfs1(nn, v, o, pre);
	}


}
void dfs(int par, int chi) {
	cn[chi] = 1;
	int  mx = 0;	
	for(auto v: adjs[chi]) {
		if (v == par) continue;
		dfs(chi,v);
		cn[chi] += cn[v];
		mx = max(mx,cn[v]);
	}
	mx = max(mx,n-cn[chi]);
	if (mx < min_mx) {
		min_mx = mx;
		center = chi;
	}
}
int main() {
	cin >> n;
	int a,b; 
	
	for(int i = 0; i < n-1; i++) {
		cin >> a >>b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	dfs(1,1);
	assert(center != -1);
	ans[center] = 1;
	dfs(center,center);
	int sum_all = 0;
	//cout << center << endl;	
	//for(int i = 1; i <=n;i++) {
	//	cout << cn[i] << " ";
	//}
	for(int v: adjs[center]) {
		subtrees.push_back({cn[v], v});
		sum_all +=cn[v];
		
	}
	sort(subtrees.begin(), subtrees.end());
	reverse(subtrees.begin(), subtrees.end());
	for(int v : adjs[center]) {
		dfs1(v, center, n - cn[v], v);
	}
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	}

