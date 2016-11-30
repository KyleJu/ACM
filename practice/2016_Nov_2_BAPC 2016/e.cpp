#include<bits/stdtr1c++.h>
using namespace std;
typedef long long ll;
ll n;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> pli;
vector<pii> edges;
vector<ll> adjs[10005];
map<pii, ll> cost;
bool vis[10005];
ll dijk() {
	priority_queue<pli, vector<pli>, greater<pli>> pq;	
	pq.push({0,n});
	while(!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		//cout << cur.first <<  " " << cur.second << " popped "<< endl;
		if(vis[cur.second]) continue;
		vis[cur.second] = true;
		if(cur.second == 1) {
			return cur.first;
		}
		for(auto v: adjs[cur.second]){
			pq.push({cur.first + cost[{v,cur.second}], v});
		}
	}
	return 1e14;
}
void init(ll w) {
	for(ll i = 0; i <= n; i++) {
		adjs[i].clear();
		vis[i] = false;
	}
	for(auto p: edges) {
		if(cost[p] >w) continue;
		adjs[p.first].push_back(p.second);
		adjs[p.second].push_back(p.first);
	}
}
int main() {
	ll m; double x; cin >> n >> m >>x;
	ll a,b; ll c;
	for(ll i = 0; i  < m ;i++) {
		cin >> a >>b >> c;
		edges.push_back({a,b});
		cost[{a,b}] = c;
		cost[{b,a}] = c;
	}
	init(1e10);
	ll val = (dijk()) * (1+x/100);
	//cout << val << endl;
	ll left = -1, right = 1e10;
	ll mid = 0;
	while(left + 1 < right) {
		mid = left + (right - left)/2;
		init(mid);
		if(dijk() <= val) right = mid;
		else left = mid;
	}
	init(left);
	if(dijk() <= val) right = left;
	cout << right << endl; 
}
