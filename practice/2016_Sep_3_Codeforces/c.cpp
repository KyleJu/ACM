#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
	int w,h; cin >> h >>w;
	double su = 0;
	vector<double> arr;
	double a;
	for(int i = 0; i < h;i++) {
		cin >>a;
		arr.push_back(a);
	}
	for(int i = 0;i <h; i++) {
		cin >> a;
		su = max(su, a + arr[i]);
	}
	//cout << w << " " << su << endl;
	cout << fixed;
	cout << setprecision(9) << ((double)w- su)/(2.0) << endl;
}
