#include<bits/stdtr1c++.h>

using namespace std;
int N;
vector<int> adjs[5005];
int sub[5005];
bool ress[5005];
bool memo[5005];
int dfs(int cur, int p) {
	int size =1;
	for(auto v: adjs[cur]){
		if(v == p) continue;
		size += dfs(v,cur);
	}
	sub[cur] = size;
	return size;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>N;
	int a, b;
	for(int i= 0; i < N-1; i++) {
		cin >> a >>b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	dfs(1,0);
	//cout << endl;
	vector<int> ss;
	stack<pair<int,int>> st;
	st.push(make_pair(1,0));
	for(int j = 1; j <=N; j++) {
		memset(memo, 0 ,sizeof memo);
		memo[0] = true;
		for(auto v: adjs[j]) {
			if(sub[v] > sub[j]) {
				ss.push_back(N-sub[j]);
			} else {
				ss.push_back(sub[v]);
			}
		}
		for(auto nn: ss) {
			for(int i = N; i >=0; i--) {
				if(memo[i]) {
					//cout << j << " tree:" << i  << " " << nn << " " << i +nn<< endl;
					memo[i+nn] = true;
					ress[i+nn] = true;
				}
			}
		}	
		ss.clear();
	}
	for(int i = 1; i<N;i++) {
		if(ress[i]) ress[N-1-i] = true;
	}
	int tm = 0;
	for(int i = 1; i<N-1; i++) {
		if(ress[i]) tm++;
	}
	//return 0;
	cout << tm << endl;
	for(int i = 1; i<N-1; i++) {
		
		if(ress[i]) cout << i << " " << N-i-1 << endl;
	}
}
