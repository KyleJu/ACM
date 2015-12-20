#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a[3];
	int b[3];
	for (int i = 0 ; i< 3; i++) {
		cin >> a[i];
	} 
	for (int i = 0; i < 3; i++) {
		cin >>	 b[i];
	}

	sort(a, a +3);
	sort(b, b +3);
	for (int i = 0 ; i < 3; i ++) {
		if (a[i] != b[i]) {
			cout << "NO" <<endl;
			return 0;
		}
	}
	int min1 = 101, ma, sum;
	for (int i = 0 ; i< 3; i ++) {
		sum += a[i];
		ma = max(ma, a[i]);
		min1 = min(min1, a[i]);
	}
	int mi = sum - min1 - ma;
	if (min1 *min1 + mi * mi != ma * ma) {
		cout <<"NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

}