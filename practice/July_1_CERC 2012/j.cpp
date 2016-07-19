#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
const int N = 1e5 + 5;
short lab[N];
queue<int> bucket[2];
int inflow[N];
int inflow1[N];
vector<int> adjs[N];
void fbucket() {
	for(int i = 0; i < n; i++) {
		inflow[i] = inflow1[i];
		if (inflow[i] ==0) {
			bucket[lab[i]].push(i);
			//cout << i << " ";
		}
	}
	//cout << "\n";
}
void topo(short b, int & res) {
	if(!bucket[0].empty() ||  !bucket[1].empty()) {
		while(!bucket[b].empty()) {
			int vv = bucket[b].front();bucket[b].pop();
			for(auto nn: adjs[vv]) {
				if(--inflow[nn] == 0) {
					//cout << nn << " " <<endl;
					bucket[lab[nn]].push(nn);
				}
			}
		}
	//	cout <<res <<endl;
		if (!bucket[b^1].empty())
		topo(b^1, ++res);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ts; cin>>ts;
	while(ts--) {
		cin >>n >>m;
		memset(inflow1, 0, sizeof inflow1);
		for(int i = 0; i < n; i++) {
			adjs[i].clear();
			lab[i] = 0;
		}
		for(int i = 0; i< n;i++) {
			cin>>lab[i];		
			lab[i]--;
		}
		int f,t;
		for(int i = 0; i < m; i++) {
			cin >> f>> t;
			f--; t--;
			adjs[f].push_back(t);
			inflow1[t]++;
		}
		int res1 = 0;
		int res2 = 0;
		fbucket();
		topo(0,res1);
		fbucket();
		topo(1,res2);
		cout << min(res1,res2) << endl;
	}	

}
