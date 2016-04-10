#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e3;
vector<int> adjs[N+5];
int cost[N+5][N+5];
bool vis[N+5];
void dfs(int v){
	vis[v] = true;
	for(auto nn : adjs[v]){
		if (vis[nn]) continue;
		dfs(nn);
	}

}
int main(){
	int ts;cin>>ts;
	while(ts--){
		int n,p; cin >> n >>p;
		memset(cost, 0, sizeof cost);
		for(int i = 0;i < n; i++){
			adjs[i].clear();
		}
		for(int i = 0;i < p; i ++){
			int a ,b,c; cin>> a >> b >>c;
			adjs[a].push_back(b);
			cost[a][b] = c;
		}
		vector<int> dis(n+2, 0x3f3f3f3f);
		dis[0] = 0;
		for(int i=0; i < n-1; i++){
			for(int j = 0; j < n; j++){
				for(auto v: adjs[j]){
					int cc = cost[j][v];
					dis[v] = min (dis[v], dis[j] + cc);
				}
			}
		}
		bool hasN = false;
		vector<int> st;
		for(int i = 0; i < n; i++){
			for(auto v: adjs[i]){
				int cc = cost[i][v];
				if (dis[v] > dis[i] + cc){
					hasN = true;
					st.push_back(v);
					st.push_back(i);
				}
			}
			//if (hasN) break;
		}
			memset(vis, 0, sizeof vis);
			for (auto nn: st){
				dfs(nn);
			}

		if (hasN&&vis[0]) cout << "possible"<< "\n";
		else cout << "not possible" << "\n";
	
	}


}

