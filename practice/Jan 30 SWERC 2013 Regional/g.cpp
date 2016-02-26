#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<string>
// edge cases !! adding yourself
// 2 - 2 !!!!
using namespace std;
int color[102];
vector<int> adjs[102];
int dups[102][102];

int n;
bool ass(int v) {
	// iterate through all egdes and assign a val
	if (v == n+1) return true;
	for(int i = 1; i<=4;i++) {
		color[v] = i;
		bool w = true;
		//cerr << "step 1" <<"\n";
		for(auto adj :adjs[v]) {
			// edge cases !! adding yourself
			if (adj >= v) continue;
			//cout << adj << " " << v << "\n";
			if (color[adj] == i) {w = false;break;}
		}
		if (w&&ass(v+1)) {
			return true;
		}
	}
	return false;
}
int main(){
	memset(color, 0, sizeof color);
	memset(dups, 0,sizeof dups);
	for(int i = 0; i < 102; i++) {
		adjs[i].clear();
	}
	cin >>n;
	string s;
	while(cin>>s) {
		int a,b,hy = 0;
		while(s[hy] !='-'){hy++;}
		a = atoi(s.substr(0,hy).c_str());
		b = atoi(s.substr(hy+1).c_str());
		//cerr << a  << " " << b << "\n";
		if (dups[a][b]) continue;
		//cerr << a  << " " << b << "\n";
		dups[a][b] = dups[b][a] = 1;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	//cerr << "here" << "\n";
	ass(1);
	for(int i = 1; i <=n; i++) {
		cout << i<< " " << color[i] << "\n";
	}
}