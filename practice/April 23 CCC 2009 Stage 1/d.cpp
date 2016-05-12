#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pq;
#define mp(a,b) make_pair(a,b)
vector<int> adjs[5005];
int cost[5005][5005];
int pcost[5005];
int tot[5005];
int main(){
ios::sync_with_stdio(0);
	int n, t; cin>> n >> t;
	for(int i = 0; i < t; i++){
		int f,t,c; cin>> f>> t>>c;
		adjs[f].push_back(t);
		adjs[t].push_back(f);
		cost[f][t] = c;
		cost[t][f] = c;
	}
	int pen; cin>> pen;
	vector<int> pens;
	for(int i =0; i < pen; i++){
		int ci, pc; cin>> ci >> pc;
		pens.push_back(ci);
		pcost[ci] = pc;
	}
	int st; cin >> st;
	priority_queue<pq, vector<pq>, greater<pq>> pqs;
	pqs.push(mp(0, st));
	bool isVis[n+5];
	memset(isVis, 0, sizeof isVis);
	while(!pqs.empty()){
		pair<int,int> cur = pqs.top(); pqs.pop();
		//cout << cur.first << " "  << cur.second << endl;
		if (isVis[cur.second]) continue;
		isVis[cur.second] = true;
		tot[cur.second] = cur.first; 
		for(auto v: adjs[cur.second]){
		//	cout << v << endl;
			if (isVis[v]) continue;
			int cc = cur.first + cost[cur.second][v];
			pqs.push(mp(cc, v));	
		}	
	}
	int cost = 0x3f3f3f3f;
	for(auto v: pens){
		int s = tot[v] + pcost[v];
	//	cout << tot[v] << " "  << pcost[v] << "\n";
		if (s < cost){
			cost = s;
		}
	}
	cout << cost;
}	
