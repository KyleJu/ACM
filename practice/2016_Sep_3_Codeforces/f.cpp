#include<iostream>

using namespace std;
int res;
void recur(int pos, int to) {
	// base base odd
	if(pos&1) {
	 res+= (pos-1)/2 +1;	
	} else {
		res += (pos/2);
		int nto = to - pos + pos/2 -1 +1;
		recur(nto,nto);
	}
}
int main() {
	int ts; cin >> ts;
	for(int i = 0; i < ts; i++) {
		int a,b; cin >> a >> b;
		res = 0;
		recur(b,a);
		cout << res << endl;
	}
}
