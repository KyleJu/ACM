#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,pair<int,int>> pq;
typedef long long ll;
#define mp(a,b) make_pair(a,b)
ifstream fin("oil.in");
ofstream fout("oil.out");
vector<int> adjs[50005];
map<pair<int,int>, int> cost;
bool vis[50005];
struct cmp {
bool operator()(const pair<int,int> & a, const pair<int,int> & b) {
	if (cost[a] == cost[b]) return a < b;
	return cost[a] > cost[b];
}
};
map<pair<int,int>,int,cmp> arr;
int main() {
ios::sync_with_stdio(0);
fin.tie(0);
freopen("oil.in", "r", stdin);
freopen("oil.out", "w", stdout);
	int n,m; ll s;
	fin >> n >> m >>s;
	int f,t,c;
	for(int i = 0; i < m; i++) {
		fin >> f>>t>>c;
		adjs[f].push_back(t);
		adjs[t].push_back(f);
		cost[mp(f,t)] = -c;
		cost[mp(t,f)] = -c;
		arr[mp(f,t)] = i+1;
		//fout << arr.size() << endl;
	}
	priority_queue<pq,vector<pq>, greater<pq>> pqs;
	int count = n;
	set<pair<int,int>> res;
	pqs.push(mp(0,mp(0,1)));
	while(!pqs.empty()) {
		pq cur = pqs.top();
		pqs.pop();
		if (vis[cur.second.second]) continue;
		vis[cur.second.second] = true;
		if (cur.second.first != 0) {
			//fout << arr.size() << " size" << endl;
			arr.erase(cur.second);
			arr.erase(mp(cur.second.second,cur.second.first));
		}
		if (--count ==0) {
			break;	
		}
		for(auto vv: adjs[cur.second.second]) {
			if (vis[vv]) continue;
			pqs.push(mp(cost[mp(cur.second.second,vv)], mp(cur.second.second, vv)));
		}
	}
	set<int> ss;
	for (auto ppp: arr) {
		//fout << ppp.second << endl;
			s += cost[ppp.first];
			if (s <0) break;
			ss.insert(ppp.second);
	}
	fout << ss.size() << endl;
	for(auto ii :ss) {
		fout << ii << " ";
	}
}
