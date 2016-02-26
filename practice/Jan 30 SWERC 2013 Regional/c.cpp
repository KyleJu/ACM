#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstring>
// when you need the path along the way
// use a visited array to keep track
// because when you update the duplicate nodes, you cannot erase from origionla pqs
// it is a little bit slower than erase
// much neater / pushing everything but use visted to keep track
// incorporate dis inside of struct or pair
using namespace std;
typedef long long ll;
typedef long double ld;
struct pq {
	int i;
	vector<int> ps;
	ld d;
	pq(int ii, vector<int>pss, ld dd): i(ii), ps(pss), d(dd){}
	bool operator<(const pq& o) const {
		return d > o.d;
	}
};
ll c[200][3];
ld dis[200][200];
vector<int> adjs[200];
int vis[200];


ld cal(int f, int t) {
	return sqrt((c[f][0] - c[t][0]) *(c[f][0] - c[t][0]) + (c[f][1] - c[t][1]) *(c[f][1] - c[t][1]) +(c[f][2] - c[t][2]) *(c[f][2] - c[t][2]));
}
int main() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> c[i][2] >> c[i][0] >> c[i][1];
		c[i][2] *=5;
	}
	for (int i = 0; i < m;i ++) {
		int f,t; string s; cin>> f>> t >>s;
		adjs[f].push_back(t);
		adjs[t].push_back(f);
		if(s == "walking" || s == "stairs") {
			dis[f][t] = cal(f,t);
			dis[t][f] = dis[f][t];
		} else if (s == "lift") {
			dis[t][f] = dis[f][t] = 1.0;
		} else {
			dis[f][t] = 1.0;
			dis[t][f]= 3* cal(t,f);
		}
	}
	int q; cin >>q;
	for(int i = 0; i < q; i++) {
		int a, b; cin>> a>>b;
		memset(vis, 0 ,sizeof vis);
		priority_queue<pq> pqs;
		pqs.push(pq(a, {}, 0));
		while(!pqs.empty()){
			pq t = pqs.top(); pqs.pop();
			//b
			if (t.i ==b) {
				cout << a;
				for(auto s: t.ps) {
					cout << " " << s;
				}
				cout << "\n";
				break;
			}
			for (auto adj: adjs[t.i]) {
				if (vis[adj]) continue;
				vector<int> ps = t.ps;
				ps.push_back(adj);
				pqs.push(pq(adj, ps, t.d + dis[t.i][adj]));
			}
			vis[t.i] = 1;
		}
	}
}