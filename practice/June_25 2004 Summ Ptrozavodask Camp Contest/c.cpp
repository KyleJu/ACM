#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> arr;
unordered_map<ll,pii> mm[3005]; 
short memo[3005][3005];
pii bt[3005][3005];
int dp(int l, int r) {
	if (l ==0) return 0;
	if (memo[l][r] != -1) return memo[l][r];
	int res = 1;
	if (mm[l].find(arr[r]) != mm[l].end()){ 
		bt[l][r] = mm[l][arr[r]];
		res = 1 + dp(mm[l][arr[r]].first, mm[l][arr[r]].second);
	}
	//cout << l << " " << r << " " << res << "\n";	
	return memo[l][r] = res;
}

int main() {
	freopen("fibsubseq.in", "r", stdin);
	freopen("fibsubseq.out","w", stdout);
	memset(memo, -1, sizeof memo);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		mm[i].max_load_factor(0.8);
		mm[i].rehash(i+5);
	}
	ll ii;
	for(int i = 0; i < n; i++) {
		cin >>ii;
		arr.push_back(ii);
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			mm[i][arr[j] +arr[i]] = make_pair(j,i);
		}
	}
	int res = 0;
	pii start;
	int rr = -1;
	for(int i = n-1; i >0; i--) {
		for(int j = i -1; j >0; j--) {
			if (i < res +2) goto end;
			if (mm[j].find(arr[i]) != mm[j].end()){
				//cout << arr[i] << " " << i << " " << j << endl;
				int tmp = dp(mm[j][arr[i]].first, mm[j][arr[i]].second);
				if (tmp > res) {
					res = tmp;
					rr = i;
					start = mm[j][arr[i]];
				}
			}
		}
	}
	end:
	if (res == 0) cout << 0 << "\n";
	else {
		stack<int> ss;
		ss.push(arr[rr]);
		ss.push(arr[start.second]);
		while(start.first != 0 && start.second !=0) {
			ss.push(arr[start.first]);
			start = bt[start.first][start.second];
		}
		cout << res +2 << "\n";
		while( !ss.empty()) {
			cout << ss.top() << " ";
			ss.pop();
		}
	}

}
