#include<iostream>

using namespace std;
#define ll long long

int arr[100005];
int main() {
	int t; cin >>t;
	for (int tc = 1; tc <=t; tc++) {
		int n; cin >> n;
		ll p; cin >> p;
		for (int i = 0; i < n; i++) {
				cin >> arr[i]; 
		}
		ll res = 0;
		int right = -1;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (right == n) {
				res += (n -i);
				continue;
			}
			//check last case !!!
			while (sum <=p) {
				right++;
				if (right == n) break;
				sum+=arr[right];
			}
			//check bound
			if ((right == n) ||sum - arr[right] <=p) {
				res += (right - i);
			}
			sum -= arr[i];
		}
		cout << "Case #" << tc << ": " << res << "\n";
	}
}