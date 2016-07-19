#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n; 
	while(cin >>n) {
		int b,t; cin >> b >> t;
		int resa, resb;
		resa = resb = 0;
		int x,y;
		x = y = 0;
		while(n || x || y) {
			if (x){
				x--;
				resa++;
			} else {
				x = min(b,n);
				n-=x;
			}
			if (y) {
				y--;
				resb++;
			} else {
				y = min (t,n);
				n-=y;
			}
		}

		cout << resa << " " << resb << endl;
	}
}
