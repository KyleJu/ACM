#include<iostream>

using namespace std;
int main() {
	long long n; cin >>n;
	int res = ((n %5) == 0)? 0:1;
	//cout << res << endl;
	cout << (n/5  + res) << endl;
}