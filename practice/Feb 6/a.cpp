#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
string s;
int main() {
	int t; cin >>t;
	while(t--) {
		int	n, k; cin >>n >> k;
		cin >>s;

		if (k==0) {
			ll res = 0;
			ll count = 0;
			for(int i = 0; i <n; i++) {
				if (s[i] == '1') {
					count =0;
				}else{
					count++;
					res +=count;
				}
			}
			cout << res << "\n";
			continue;
		}
		// keep track last 1 and to next 1
		// if 0 in between keep adding

		// left indicates the last position of 1
		int left = -1;
		//right is the next one
		int right = 0;
		int bcount = 0;
		ll res = 0;
		int base = (int)'0';
		while((right < n) && (bcount + (int)s[right] - base) <k) {
				bcount += ((int)s[right]-base);
				right++;
				continue;
		}
		//cout << right << " loop\n";
		int c = 0;
		while(right <n) {

			//find next one from last one
			// check the case if left and right are the same ******
			// how many 0 in betweens
			while(s[++left] != '1') {
				c++;
			}
			c++;
			res += c;
			//cerr << res <<"\n";
			while (((right +1) <n) && (s[right +1] != '1')) {
				res += c;
				right++;
			}
			if (right == n-1) {
				break;
			}
					//	cerr << res << "here" <<"\n";
			right++;
			c =0;
			//cerr << "what is right " << right<<endl;
		}

		cout << res << "\n";
	}
	
}