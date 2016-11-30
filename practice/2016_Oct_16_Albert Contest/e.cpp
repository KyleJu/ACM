#include<bits/stdtr1c++.h>

using namespace std;

int main() {
	int ts; cin >>ts;
	for(int i = 1 ; i<= ts; i++) {
		int r, c;  cin >> r >> c;
		vector<string> arr;
		string tm;
		for(int t = 0 ;t < r; t++) {
			cin >> tm;
			arr.push_back(tm);
		}
		cout <<"Test " << i << endl;
		for(int x = r-1; x>=0 ;x--) {
			for(int y = c-1; y>=0; y--) {
				cout << arr[x][y];	
			}
			cout << endl;
		}

	}

}
