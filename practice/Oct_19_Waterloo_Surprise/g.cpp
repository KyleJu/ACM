#include<bits/stdtr1c++.h>

using namespace std;
int arr[2000*2 +5];
int main() {
	int n; cin >> n;
	for(int i = n; i< n+n; i++) {
		cin >> arr[i];
	}
	for(int i =  n-1; i >=0; i--) {
		arr[i] = arr[n-(i)-1 +n];
	}
	vector<int> res(2*n+1, 0x3f3f3f3f);
	vector<int>::iterator it;
	for(int i = 0; i < 2*n; i++) {
		cout << *lower_bound(res.begin(),res.end(), arr[i]) << endl;
		*lower_bound(res.begin(),res.end(), arr[i]) = arr[i]; 
		for(int i  = 0; i < n; i++ ) {
			cout << res[i] << " " ;
		}
		cout << " list ended" <<endl;
	}
	int ss = 0;
	for(int i = 0; i< 2*n; i++) {
		if (res[i] != 0x3f3f3f3f) ss++;
		else break;
	}
	cout << ss << endl;

}
