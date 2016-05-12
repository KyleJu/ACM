#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define ss(a) atoi(a.c_str())
unordered_map<string, int> sti;
vector<string> adjs[10005];
vector<long long> by;
bool arr[10005];

int main() {
	int b;
	while (cin>>b){
		sti.clear();
		memset(arr, 0, sizeof arr);
		by.clear();
		for(int i = 0; i < 10005; i++) {
			adjs[i].clear();
		}
		int st; cin >>st;
		for(int i = 0; i <b; i++){
			string s; cin>> s;
			sti[s] = i;
			long long bytes; int pt; cin >>bytes >>pt;
			by.push_back(bytes);
			for (int j = 0;  j< pt; j++) {
				string tm; cin >>tm;
				if (ss(tm) ==0) continue;
				adjs[i].push_back(tm);
			}
		}
		queue<int> q;
		for (int i = 0; i < st; i++) {
			string s; cin>>s;
			q.push(sti[s]);
		}

		while(!q.empty()){
			int no = q.front(); q.pop();
			arr[no] = true;
			for (auto nno: adjs[no]) {
				if (arr[sti[nno]]) continue;
				q.push(sti[nno]);
			}
		}
		long long res = 0;
		for (int i = 0; i < b; i++){
			if (arr[i]) continue;
			res += by[i];
		}
		cout << res << endl;

	}
}