#include<iostream>
#include <fstream>
#include<vector>
#include<set>
#include<algorithm>
//forget to check s if greater to 0 all the time
// forget to initialize root with i
// index issue: all the way to n
using namespace std;
typedef long long ll;
const int N = 50005;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<int,piii> piiii;
set<piiii,greater<piiii>> ss;
ifstream fin("oil.in");
ofstream fout("oil.out");
int rk[N];
int root[N];
int find(int nn) {
	if (root[nn] ==nn) return nn;
	root[nn] = find(root[nn]);
	return root[nn];
}


void un(int a, int b) {
	int ra = root[a];
	int rb = root[b];
	if (rk[ra] < rk[rb] ) {
		root[ra] = rb;	
	} else if (rk[rb] < rk[ra]) {
		root[rb] = ra;
	} else {
		root[rb] = ra;
		rk[ra]++;
	}
}
//ios:sync_with_stdio(false);
//fin.tie(0);
int main() {
    std::ios::sync_with_stdio(false);
	    fin.tie(0);
	int n,m; ll s;
	fin >> n >>m >>s;
	int f,t,c;
	for(int i = 0; i <m; i++) {
		fin >>f >>t >>c;
		ss.insert(make_pair(c, make_pair(i+1,make_pair(f,t))));
	}
	for(int i = 0; i <= n; i++) {
		root[i] = i;
	}
	int count = 0;
	for(set<piiii>::iterator it = ss.begin(); it != ss.end(); ) {
		pii cur = (*it).second.second;
		if (find(cur.first) == find(cur.second)) {
			it++;
		} else {
			count ++;
			un(cur.first, cur.second);
			it = ss.erase(it);
			if (count == n-1) break;
		}
	}
	set<piiii>::iterator it = ss.end();
	vector<int> res;
	while(it != ss.begin() && s >=0) {
		--it;
		s -= (*it).first;
		if (s <0) break;
		res.push_back((*it).second.first);
	}
	fout << res.size() << endl;
	for(auto pp: res) {
		fout << pp  << " ";
	}
	fout << endl;
	
}
