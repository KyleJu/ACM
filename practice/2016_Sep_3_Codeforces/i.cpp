#include<bits/stdtr1c++.h>

using namespace std;
const int N = 1e4 +5;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
vector<int> adjs[N];
int seen[N];
vector<piii> res;
int dfs(int v) {
	if(seen[v] ==2) return -1;
	seen[v] = 1;
	
	vector<int> um;
	for(auto n: adjs[v]) {
		if( seen[n] ==1) continue;
		int w = dfs(n);
		if(w != -1) {
			res.push_back(piii(w, pii(n,v)));		
		} else {
			um.push_back(n);
		}
	}
	seen[v] =2;
	for(int i = 1; i< um.size() ; i+=2) {
		res.push_back(piii(um[i-1], pii(v, um[i])));
	}
	return um.size()%2 == 0? -1: um.back();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	memset(seen, 0, sizeof seen);
	 cin >> n >> m;
	 int a,b;
	 for(int i = 0; i < m; i++) {
	 	cin >> a >>b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	 }
		dfs(1);
	cout << res.size() << endl;
	for(piii x :res) {
		cout << x.second.second <<  " " << x.second.first << " " << x.first << endl;	
	}
	
}
