#include<bits/stdtr1c++.h>

using namespace std;
bool vis[50000];
vector<int> arr;
int des;
void dfs(int cur) {
	if(cur > des) return;
	if(vis[cur]) return;
	vis[cur] = true;
	
	if(cur == des) return;
	dfs(cur + arr[cur-1]);
}
int main() {
	int n; cin >> n >> des;
	for(int i = 0; i < n-1; i++) {
		int tm; cin >> tm;
		arr.push_back(tm);
	}
	dfs(1);
	if(vis[des]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" <<endl;
	}
}
