#include<bits/stdtr1c++.h>


using namespace std;

int main() {
	int n, d, w; cin>> n >> d >> w;
	int o;
	int to = 0;
	int res = 0;
	for(int i = 0; i < n; i++) {
		cin >> o;
		if (o >d) continue;
		to += o;
		if (to > w) {
			to =0;
			res++;
		}
	}
	cout << res << endl;

}
