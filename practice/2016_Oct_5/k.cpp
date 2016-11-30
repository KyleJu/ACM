#include<bits/stdtr1c++.h>

using namespace std;
struct pq {
	int c, p, to;
};
struct cmp {
	bool operator()(const pq & a, const pq&b) {
		if (a.c == b.c)
			return a.to < b.to;
		return a.c < b.c;
	}
};
map<pair<int,int>, set<int>> check;
vector<int> adjs[105];
int cost[105];
bool vis[105];
int main() {
	int n; cin >>n;
	int num;	
	int ne, t, pa;
	for(int i = 1; i <= n; i ++) {
		cin >> num >> cost[i];
		for(int j = 0; j < num; j++) {
			cin >> ne >> t;
			adjs[i].push_back(t);
			for(int z = 0; z < ne; z++) {
				cin >> pa;
				check[{i,t}].insert(pa);
			}
		}
	}
	priority_queue<pq, vector<pq>,cmp> poq;
	pq start; start.c =cost[1]; start.p = -1; start.to = 1;
	poq.push(start);
	bool f = false;
	while(!poq.empty()) {
		pq cur = poq.top(); poq.pop();
		//cout << cur.to << " " << cur.p << endl;
		// TODO: check vis
		if(vis[cur.to]) continue;
		vis[cur.to] = 1;
		if(cur.to == n) {
			cout << cur.c << endl;
			f= true;
			break;
		}
		for(auto v: adjs[cur.to]) {
			if(check[{cur.to, v}].find(cur.p) != check[{cur.to, v}].end()) {
				if(v != n) continue;
			}
			pq nn;
			nn.c = cur.c + cost[v];
			nn.to = v;
			nn.p = cur.to;
			poq.push(nn);
		}
	}
	if(!f) cout <<"impossible" << endl;
}
