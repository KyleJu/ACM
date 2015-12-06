#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;


int n;
vector<int> adjs[205];
pii edge[205];
int dia[205][205];
int depth[205][205];
//depends on the edge!!!
int fdep(int node, int enode) {
	if (depth[node][enode] != -1) return depth[node][enode];
	int res = 0;
	//dfs
	for (auto ver :adjs[node]){
		if (ver == enode) continue;
		res = max(res, 1 + fdep(ver, node));
	}
	return depth[node][enode] = res;
}

int dp(int node, int enode) {
	if (dia[node][enode] != -1) return dia[node][enode];
	int res = 0;
	// the diameter of children's left subtree
	for (auto ver :adjs[node]) {
		if (ver == enode) continue;
		res = max(res, dp(ver,node));
	}
	int ml1 = 0, ml2 = 0;
	for (auto ver :adjs[node]) {
		if (ver == enode) continue;
		int temp = 1 + fdep(ver,node);
		if (ml1 < temp) {
			ml2 = ml1;
			ml1 = temp;
		} else {
			ml2 = max(ml2,temp);
		}
	}
	res = max(res, ml1 + ml2);
	return dia[node][enode] = res;
// the longest path between leaves that goes through the root of T

}

int main() {
	cin >> n;
	for (int i = 0; i < n -1; i++) {
		int a, b; cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
		edge[i] = make_pair(a,b);
	}
	memset(depth, -1, sizeof depth);
	memset(dia, -1, sizeof dia);
	int res = 0;
	for (int i = 0; i < n -1; i++) {
		//cout <<dp(edge[i].first, edge[i].second) << " " << dp(edge[i].second, edge[i].first) << endl;
		res = max(res, dp(edge[i].first, edge[i].second) * dp(edge[i].second, edge[i].first));
	}
	cout << res << endl;		
}
