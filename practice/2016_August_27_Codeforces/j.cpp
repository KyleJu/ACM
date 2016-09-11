#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int d; double c; cin >> d >> c;
	vector<int> arr;
	double ex = 0;
	for(int i = 0;  i <d; i++) {
		int nn; cin >>nn;
		arr.push_back(nn);
		if (i !=0) {
			if(arr[i-1] !=nn) ex += ((c-1)/c);
		}
	}
	cout << fixed;
	cout << setprecision(8) << ex << endl;

}
