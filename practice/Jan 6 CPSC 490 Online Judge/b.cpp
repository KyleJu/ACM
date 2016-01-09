#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int a[100005]; 
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) {
			cin >> a[i]; 
		}
		int res = -20001;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + a[i] < 0) {
				sum = 0;
			} else {
				sum+=a[i];
			}
			res = max(res, sum);
		}
		cout << res << "\n";
	}
	return 0;
}