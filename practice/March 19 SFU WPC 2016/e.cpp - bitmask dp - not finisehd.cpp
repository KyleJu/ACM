#include <bits/stdtr1c++.h>
using namespace std;
vector<int> adjs[5005];
vector<int> cc;
int ses[5005];
bool seen[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		cc.clear();
		for (int i = 0; i< 5005; i++){
			adjs[i].clear();
			ses[i] = 0;
		}
		int s,f; cin >> s >> f;
		for(int i = 0; i < n; i++){
			int tm; cin >> tm;
			cc.push_back(tm);
		}
		for(int i = 0;i  <f; i++){
			int l,r; cin>>l >>r;
			adjs[l].push_back(r);
			adjs[r].push_back(l);
		}
		for(int i = 0; i < s; i++){
			int ii; cin>>ii;
			for(int j = 0; j < ih; j++){
				int tm; cin>>tm;
				ses[tm] = (ses[tm] | (i<<i));
			}
		}
		memset(seen, 0, sizeof seen);		
		//compress friends and secrets, costs
		for(int i = 0;i < n; i ++){
			
		}



	}

}
