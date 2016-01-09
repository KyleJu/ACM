#include<iostream>
#define ll long long
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		cout << a + b << " " << a - b << " " << a*b << "\n";	
	}
	return 0;
}