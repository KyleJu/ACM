#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pii;
vector<pii> arr;
map<pii,int> m;
int main() {
	int n; cin >>n;
	pii nth;
	int a,b;
	for (int i = 1; i <= n; i++) {
		cin >> a >>b;
		pii p = make_pair(a,b);
		arr.push_back(p);
		m[p] = i;
		if (i ==n) nth = p;
	}
	sort(arr.begin(), arr.end());
	int val = 1;
	int in = -1;
	int mm = -1;
	bool reach = true;
	vector<int> res;
	for(int i = 0; i  < n; i ++) {
		pii cur = arr[i];
		if (cur.first <= val) {
			if (cur.second > mm) {
				in = i;
				mm = cur.second;
			}
		} else{
			if (mm >=nth.first) {
				res.push_back(m[arr[in]]);
				res.push_back(n);
				break;
			}
			if ( mm < cur.first) {
				reach = false;
				break;
			} else {
				res.push_back(m[arr[in]]);	
				val = mm;
				i--;
			}
		}	
	}
	int ss = res.size();
	if (ss == 0 || res[ss-1] != n ) {
		res.push_back(n);
	}

	if (!reach) {
		cout <<"No such luck" << endl;
	} else {
		cout << res.size() << endl;
		for (int ii : res) {
			cout << ii <<" ";
		}
		cout << endl;
	}


}
