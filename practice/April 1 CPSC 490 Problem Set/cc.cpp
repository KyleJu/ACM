#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

//create a vector every time
//got TLE
unordered_map<string,unordered_set<string>> adj;
unordered_map<string, int> col;


bool dfs(string s){
	if (col[s] == 1) return true;
	else if (col[s] ==2) return false;
	col[s] = 1;
	for(auto v: adj[s]){
		if ( dfs(v)) return true;
	}
	col[s] = 2;
	return false;
}
string f(string s){
	if (s[1] == '+') s[1] = '-';
		else s[1] = '+';	
		return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ts; cin>>ts;
	while(ts--){
		int n; cin>>n ;
		adj.clear();
		vector<string> v;
		for(int i = 0;i <n ;i++){
			string tm; cin>>tm;
			v.clear();	
			for(int j = 0; j < 4; j++){
				v.push_back(tm.substr(2*j, 2));
			}

			for(int x = 0; x <4; x++){
				for (int y = 0; y < 4; y++){
					if (x==  y || v[x] == "00" || v[y] == "00") continue;
					adj[v[x]].insert(f(v[y]));
				}
			}
		}

			col.clear();
			bool res = false;
			for (auto ss :adj) {
				if (col.find(ss.first) != col.end()) continue;
				if (dfs(ss.first)) {
					//cout << ss.first << endl;
					res = true;
					break;
				}
			}
			if (res) cout << "unbounded\n";
			else cout << "bounded\n";
	}
}
