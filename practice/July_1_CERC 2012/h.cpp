#include<iostream>
#include<cmath>
using namespace std;

double ra(int a, int b) {
	return sqrt(a*a + b*b);
}
int main() {
	int ts; cin>> ts;
	while(ts--) {
		int n; cin >>n;
		int  res = 0;
		int a,b;
		for(int i = 0;  i <n; i++) {
			cin >> a >>b ;	
			double cur = ra(a,b)-0.0001;
			int sc = 10 - (int) (cur/20);
			if (sc <0) continue;
			res += (sc);
		}
		cout << res << "\n";
	}
}
