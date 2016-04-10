#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define mp(a,b) make_pair(a,b)
typedef pair<int,int> pii;
typedef vector<int> vii;
bool vis[(int)1e4 +5];
vii adjs[(int)1e4+5];
pii  cost[(int)1e4 +5][(int)1e4+5];
typedef pair<int, pair<char,int>> piii; 
int main(){
	int ts; cin>>ts;
	while(ts--){
		int n, m; cin>> n >>m;
		for(int i = 0; i <n; i++){

			adjs[i].clear();	
		}
		memset(vis, 0, sizeof vis);
		//memset(cost, -1, sizeof cost);
		int mc = 0;
		int tc = 0;
		for (int i =0; i < m; i ++){
			char t; int a,b,c; cin>> t >> a>> b >>c;
			if (t=='B'){
				mc++; tc += c;
				cost[a][b] = mp(0,t);
				cost[b][a] = mp(0,t);
			} else {
				cost[a][b] = mp(c,t);
				cost[b][a] = mp(c,t);
			}
			adjs[a].push_back(b);
			adjs[b].push_back(a);
		}
		priority_queue<piii, vector<piii>, greater<piii>> pqs;
		//get the first node
		for(auto v: adjs[0]){
			pii no = cost[0][v];
			pqs.push(mp(no.first,mp(no.second,v)));
		}
		int res = 0;
		vis[0] = true;
		while(!pqs.empty()){
			piii cur = pqs.top(); pqs.pop();
			if (vis[cur.second.second]) continue;
			vis[cur.second.second] = true;
			if (cur.second.first =='B') mc--;
			res +=cur.first;
			for(auto v: adjs[cur.second.second]){
				if (vis[v]) continue;
				pii nc = cost[cur.second.second][v];
				pqs.push(mp(nc.first, mp(nc.second, v)));
			}
		}
		if (mc>0) cout << "NOPE" << endl;
		else cout<< res + tc << endl;
	}
}
