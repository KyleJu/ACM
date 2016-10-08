#include<bits/stdtr1c++.h>

using namespace std;
int cost[505];
deque<int> sta;
bool vis[505];
int main() {
	int n, m; cin >> n >> m;
	for(int i = 1 ;i <=n; i++) {
		cin >> cost[i];
	}
	vector<int> arr;
	int tm;
	for(int i = 0; i < m; i++) {
		cin >> tm;
		arr.push_back(tm);
		if(!vis[tm]) {
			sta.push_back(tm);
			vis[tm] = true;
		}
	}
	int cos = 0;
	for(auto d: arr) {
		for(int i = 0; i < n; i++) {
			if(sta[i] == d) {
					
				sta.erase(sta.begin() + i);
				sta.push_front(d); break;
			} else {
				cos +=cost[sta[i]];	
			}
		}
		//cout << d << " " << cos << endl;
	}
	cout << cos << endl;

}
