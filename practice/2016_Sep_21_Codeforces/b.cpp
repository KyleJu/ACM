#include<bits/stdtr1c++.h>

using namespace std;
vector<int> adjs[305];
vector<pair<int,int>> arr;
bool vis[305];
int res[305];
void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur] = true;
	for(auto v: adjs[cur]) {
		if(vis[v]) continue;
		dfs(v);
	}
}
int main() {
	int n; cin >> n;
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a; arr.push_back({a,i});	
	}
	string ss;
	vector<string> s;
	for(int i = 0 ;i < n;i++) {
		cin >>ss;
		s.push_back(ss);	
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <i+1; j++) {
			if(i ==j) continue;	
			if(s[i][j] == '1') {
				//cout << i << " " << j <<endl;
				adjs[i].push_back(j);
				adjs[j].push_back(i);
			}
		}
	}	

	sort(arr.begin(), arr.end());
	for(auto pp: arr) {
		//cout << pp.first << " " << pp.second << endl;
		memset(vis, 0, sizeof vis);
		dfs(pp.second);
	//	for (int i = 0; i < n; i++) {
			//cout << vis[i] << " ";
	//	}
		//cout <<endl;
	 	for(int i = 0; i < n; i++) {
			if(vis[i] && (res[i]==0)) {
				res[i] = pp.first;
				break;
			}
		}	
	}
	for(int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	
}
