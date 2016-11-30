#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, pair<int,int>> pii;
vector<pii> arr;
const int N = (int)5*(1e4) + 5;
int rank[N];
int root[N];
int find(int a) {
	if(root[a] == a) return a;
	root[a] = find(root[a]);
	return root[a];
}
void un(int a, int b) {
	int ra = find(a);
	int rb = find(b);
	if(root[ra] <root[rb]) {
		root[ra] =rb;
	} else if(root[rb] <root[ra]) {
		root[rb] = ra;	
	} else {
		root[ra] = rb;
		root[rb]++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m,l;
	cin >> n >> m >> l;
	int d,t,c;
    ll cost = 0;	
	for(int i = 0; i < m; i++) {
		cin >> d >> t >> c;
		if(i <l) cost += c;
		arr.push_back({c,{d,t}});	
	}
	for(int i = 1; i <=n; i++) {
		root[i] = i;
	}
	set<int> ch;
	sort(arr.begin(), arr.end());
	ll to = 0;
	int s = 0;
	for(auto pp: arr) {
		if(find(pp.second.first) == find(pp.second.second))continue;
		//cout << pp.second.first <<  " " <<pp.second.second << endl;
		to += pp.first;
		un(pp.second.first, pp.second.second);
		s++;
		ch.insert(pp.second.first);
		ch.insert(pp.second.second);
		if(s == n-1) break;
	}
	if(to <= cost) {
		if(ch.size() != n) cout << "impossible" << endl;
		else cout << "possible" << endl;
	} else {
		cout <<"impossible" << endl;
	}
}
