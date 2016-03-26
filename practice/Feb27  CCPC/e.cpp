#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
// problem
//if (ti[p.second] <= p.first && ti[p.second] != -1) continue;
// if fast, don't push at all

#define mp(a,b) make_pair(a,b)
typedef pair<int, int> pii;
bool visited[1005];
int ti[1005];
int adjs[1005][1005];
vector<int> tra[1005];
bool tls[1005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	int ts; cin >>ts;
	while(ts--) {
		int n, m, na, nt; cin >> n >>m >> na >>nt;
		memset(visited, 0 ,sizeof visited);
		memset(ti, -1, sizeof ti);
		memset(adjs, -1, sizeof adjs);
		memset(tls, 0, sizeof tls);

		priority_queue<pii, vector<pii>, greater<pii>> pq;
		priority_queue<pii, vector<pii>, greater<pii>> ppq;
		for(int i =0; i < 1005; i++) {
			tra[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int a,b,c; cin >> a >> b >>c;
			adjs[a][b] = c;
			adjs[b][a] = c;
			//cout << a << " " << b << adjs[a][b];
			tra[a].push_back(b);
			tra[b].push_back(a);
		}

		// for (auto tt: tra[0]) {
		// 	cout << tt << "\n";
		// 	cout << adjs[0][tt] << "\n";
		// }
		for(int i = 0; i < na; i ++) {
			int a; cin >>a;
			pq.push(mp(0,a));	
		}
		//cerr << "here " <<"\n";
		for (int i =0; i < nt; i++) {
			int des; cin>> des;
			tls[des] = true;
		}
		while(!pq.empty()){
			//cerr << "q1" << "\n";
			pii p = pq.top();
			pq.pop();
			if (visited[p.second]) continue;
			visited[p.second] = true;
			ti[p.second] = p.first;
			for(int ad: tra[p.second]) {
				pq.push(mp(p.first + adjs[p.second][ad], ad));
			}
		}
		memset(visited, 0, sizeof visited);
		ppq.push(mp(0,0));
		bool e = false;
		while(!ppq.empty()){
			//cerr << "q2 " << "\n";
			pii p = ppq.top(); ppq.pop();
			if (visited[p.second]) continue;
			visited[p.second] = true;
			//cerr << p.first << "  " << p.second << "\n";

			if (ti[p.second] <= p.first && ti[p.second] != -1) continue;
			if (tls[p.second]) {
				e = true;
				cout << p.first<< "\n";
				break;
			}
			for (int no: tra[p.second]) {
				//cerr << no << "\n";
				ppq.push(mp(p.first + adjs[p.second][no], no));
			}

		}
		if (!e) 
		cout << "Neo may fight an Agent" << "\n";

	}
}