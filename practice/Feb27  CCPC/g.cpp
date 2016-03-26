#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
multiset<int> sset;
int main(){
	int ts; cin >>ts;
	while (ts--) {
		sset.clear();
		int n, k; cin >>n >>k;
		int res = 0;
		int mi = 10000000;
		int ct = 0;
		for (int i = 0; i< n; i++) {
			string s; cin >> s;
			if (s == "insert") {
				int num; cin >> num;
				ct ++;
				if (ct <=k) {
					res ^= num;
					sset.insert(num);
				} else {
					if (num >= mi) {
						sset.insert(num);
						sset.erase(sset.find(mi));
						res ^= mi;
						res ^= num;
					} 
				}
				mi = *sset.begin();
				//cout << mi << endl;
 			} else {
				cout << res <<"\n";
			}

		}
	}
}