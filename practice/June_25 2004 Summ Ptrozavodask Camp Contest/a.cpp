#include<iostream>

using namespace std;

int main() {
freopen("assign.in", "r", stdin);
freopen("assign.out", "w", stdout);
	int n; cin>>n;
	cout << 0 << " " << 1 << " ";
	for(int i = 2; i < n; i++) {
		cout << 100 << " ";
	}
	cout << "\n";
	cout << 1 << " ";
	for (int i = 1 ; i < n; i++) {
		cout << 100 << " ";
	}
	cout << "\n";
	for(int i = 2; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << 100 << " ";
		}
		cout << "\n";
		}
}
