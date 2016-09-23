#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int main() {
	int n, c; cin>> n >>c;
	int left = 0;
	int right = 0;
	int p = 0;
	int f,l;
	for(int i = 0; i < n; ++i) {
		cin >> p;
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end());
	f = arr[0];
	l = arr[n-1];
	if (f<=c) left = c -f;
	if (l >c) right = l - c;
	if(n ==1) {
		cout << 0 << endl;
		return 0;
	}
	if(f == c && l == c) {
		cout << 0 << endl;
		return 0;
	}

	int res = 0x3f3f3f3f;
	if( f>=c) {
		res = min(res, arr[n-2] -c);
	} else if(l <=c) {
		res = min(res, c - arr[1]);
	} else {
	int ll = left - min(c-f, arr[1] - f);
	res = min(res,ll+right + min(ll,right)); 
	int rr = right - min(l - c, l - arr[n-2]);
	res = min(res, left + rr + min(left,rr));
	}
	cout << res << "\n";

/*
	int res = 0x3f3f3f3f;
	int ll = left - min(c-f, arr[1] - f);
	res = min(res,ll+right + min(ll,right)); 
	int rr = right - min(l - c, l - arr[n-2]);
	res = min(res, left + rr + min(left,rr));
	if( f>=c) {
		res = min(res, c - arr[1]);
	}
	if(l <=c) res = min(res, arr[n-2] -c);
	cout << res << "\n";
*/
}
