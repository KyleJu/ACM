#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int n;
// total sum -> rather two binary search on combinaton won't work because it doesnt follow linear modle
// the reason you use binary search because it is a search question and you think about cutoff rather than scan one by one
long long work(int pp) {
	long long pos = 0;
	for (int i = 0; i <n; i++) {
		vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), pp- arr[i]);	
		if(it == arr.begin() || (it-1) - (arr.begin() +i) <=0) break;
		--it;
		int tm = it - (arr.begin()+i);
		pos+=tm;
	}
	return pos;
}
int main() {
	long long pos; cin >> n >> pos;
	int a;
	for (int i= 0; i < n ; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int r = arr[n-1] + arr[n-2];
	int left = 0;
	int mid = 0;
	//left exclusive and right inclusive
	while(left + 1 < r) {
		mid = left + (r - left)/2;	
		if(work(mid) >= pos) {
			//cout << left << " " << r << " work " << mid<< " " <<  work(mid) <<endl;
			r = mid;
		} else {

			//cout << left << " " << r << " not work " << mid << " " << work(mid) <<endl;
			left = mid;
		}
	}
	cout << r << endl;
}
