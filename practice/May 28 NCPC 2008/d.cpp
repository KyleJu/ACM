#include<iostream>

using namespace std;

int main() {
	int n,b,h,w;
	cin >> n >> b >> h>>w;
	int p, va;
	int res = 0x3f3f3f3f;
	for (int i = 0; i < h; i++) {
		int temp = 0;
		 cin >>p;
		for(int j =0; j < w; j++) {
			cin>>va;
			temp = max(temp,va); 
		}
		if (temp >= n) res = min (res, n*p);
	}

	if (res > b) cout << "stay home";
	else cout <<res;

}
