#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;

int pc(int n, int t, int mid) {
	int cn = 1;
	int pre = arr[0];
	for (int i =1; i<n;i++) {
		//check if cur dis works
		if (arr[i] - pre >=mid) {
			pre = arr[i];
			cn++;
			if (cn==t) {
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int t; cin >>t;
	while(t--) {
		arr.clear();
		int n , t; cin >> n >> t;
		for (int i = 0; i <n;i++) {
			int tem; cin >>tem;
			arr.push_back(tem);
		}
		sort(arr.begin(),arr.end());
		int left = 0;
		int right = arr[arr.size()-1] - arr[0];
		//if I do left inclusive and right exclusive 
		// the loop should be left + 1 < right because they will be at leats 1 aprt
		// 
		//cerr << left << " " << right << "\n";
		while(left + 1 < right) {
			//cerr << left << " " << right << "\n";
			int mid = (left + right)/2;
			//if mid works go right
			// left should always work
			// right always not working -> you won't know which one is working
			if (pc(n,t, mid)){
				left = mid ;
			} else {
				right = mid;
			}
		}
		
		cout << left << "\n";
	}
	return 0;
}