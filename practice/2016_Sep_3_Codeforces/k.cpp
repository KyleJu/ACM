#include<iostream>

using namespace std;

int main() {
	int n; cin >> n;
	long double top = 1;
	long double  bo = 1;
	int res = 0;
	if(n ==1) {
		cout << 2 << endl;
		return 0;
	}
	if(n ==2 ) {
		cout << 3 <<endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		//cout << top << " " << bo << endl;
		top *= (n-i);
		bo *= n;
		if(top/bo < 0.5) {
			res = i+ 1;
			break;
		}
	}
	cout << res << "\n";
}
