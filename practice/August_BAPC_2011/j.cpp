#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
		cin.tie(0);
	int n,s; cin>>n;
	while(n--) {
		cin >>s;
		bool res = false;
		int i = 0;
		int  dd = 0;
		if (s==1) {
			cout << 0 << " " << 1 << endl;
			continue;
		}
		for( i = sqrt(s); i >=1; i--) {
			if ( s%i==0) {
				int b = s/i;
				if (!((b - i)&1)&& !((b + i)&1)) {
					cout << (b-i)/2 << " " << (b+i)/2 <<endl;
					res = true;
					break;
					
				}
			}
		}
		if (!res) {
			cout << "IMPOSSIBLE"<<endl;
		}
	}
}
