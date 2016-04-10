#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
vector<int> adj1[10004];
int cost[10004][10004];
bool vis[10004];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	int ts; cin>>ts;
	while(ts--){
		//memset(cost, -1, sizeof cost);
		int n,r,s; cin >> n >> r>> s;
		for(int i = 0; i < n+3;i++){
			adj1[i].clear();
			vis[i] = 0;
			for(int j = 0; j < n+3; j++){
				cost[i][j] = -1;
			}
		}
		for(int i =0; i < r; i++){
			string t; int a,b; cin>> t >> a >> b;
				adj1[a].push_back(b);
				adj1[b].push_back(a);
			if (t == "E"){
				cost[a][b] = 1;
				cost[b][a] = 1;
			} else{
				//
				cost[a][b] = 0;
				cost[b][a] = 0;
			}
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
	// check conncetion and count edges	
		int maxS = -1;
		int to = 0;
		pq.push(make_pair(0, 0));
		while(!pq.empty()){
			
			pii cur = pq.top();pq.pop();	
		//	cerr << cur.first << " " << cur.second<< endl;
			if (vis[cur.second]) continue;
			vis[cur.second] = true;
			
			if (cur.first ==0) maxS++;
			for(auto v: adj1[cur.second]){
				if (vis[v]) continue;	
				pii nn = make_pair(cost[cur.second][v], v);
				//cerr<< v <<" " <<  cur.second <<"here" << endl;
				pq.push(nn);
			}
		//	to++;
		//	if (to == n) break;

		}
	bool res = true;
		for(int i = 0; i < n; i++){
			if (!vis[i]) {
				res = false;
				break;
			}
		}
		if (!res) {
			cout << "NO" << "\n";
			continue;
		}

	to = 0;
	int minS=0;	
	priority_queue<pii, vector<pii>, greater<pii>> pq1;
	memset(vis, 0, sizeof vis);
	pq1.push(make_pair(0,0));
	while(!pq1.empty()){
		pii cur = pq1.top(); pq1.pop();
		if (vis[cur.second]) continue;
		vis[cur.second] = true;
		if (cur.first == 1)minS++;
		for(auto v: adj1[cur.second]){
			if (vis[v]) continue;
			pii nn = make_pair(abs(cost[cur.second][v]-1),v);
			pq1.push(nn);
		}
	//	to ++;
	//	if (to == n) break;
	}

	//cout << minS << " " << maxS<< endl;
	if (minS<=s && s <= maxS) cout << "YES\n";
	else cout << "NO\n";
		
	}

}


