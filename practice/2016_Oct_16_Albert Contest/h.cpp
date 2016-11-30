#include<iostream>

using namespace std;


int main(void) {
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		if((n/400)*400 >= n) {
		cout << n/400 << endl;
		} else {
			cout << n/400 + 1 << endl;
		}
	}

	return 0;
}
