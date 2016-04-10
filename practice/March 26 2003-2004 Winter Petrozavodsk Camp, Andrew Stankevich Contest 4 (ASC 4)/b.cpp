#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include <cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> adjs[10005];
int num = 0;
int dep[10005];
int mdp[10005];
int res = 0;
int parent[10005];
vector<int> ve;
map<pii,int> ma;
map<pii,bool> du;
void bd(int u) {
	dep[u] = mdp[u] = ++num;
	for(auto ne : adjs[u]){
		if (dep[ne] == 0){
			parent[ne] = u;
			bd(ne);
			if (dep[u] < mdp[ne]){
				// not connected
				if (du[make_pair(u,ne)]) continue;
				res++;
				ve.push_back(ma[make_pair(u,ne)]);
			}
			mdp[u] = min(mdp[u], mdp[ne]);
		} else if (ne != parent[u]) {
		
			mdp[u] = min(mdp[u], dep[ne]);
		}
	}

}
int main(){
	freopen("bridges.in","r",stdin);
	freopen("bridges.out","w",stdout);
	
	int n,m; cin >> n >>m;
	for(int i =1; i <= m; i++){
		int a,b; cin>> a>>b;
		if (ma[make_pair(a,b)] !=0) {
			du[make_pair(a,b)] = true;
			du[make_pair(b,a)] = true;
		}
		adjs[a].push_back(b);
		adjs[b].push_back(a);
		ma[make_pair(a,b)] = i;
		ma[make_pair(b,a)] =i;
	}
	for(int i=1; i <=n;i++){
		if(dep[i]!=0) continue;
		bd(i);
	}
	cout << res << "\n";
	for(auto s: ve){
		cout << s << " ";
	}
	cout << "\n";
}
