#include<iostream>
#include<string>
using namespace std;

bool fir;
bool sec;
string l1;
string l2;
int calg(int a, int b , bool isF) {
	// case 0?                        **** come back


	//two b next to each other
	if (b - a == 1) return 0;
	if (b - a == 2 ) {
		if ((isF && fir) || (!isF && sec)) return 0;
		//what if sec is no??          *** come back
		if (isF) sec = true;
		else fir = true;
		return 1;
	}
	if (b - a > 2) {
		if ((isF && fir) || (!isF && sec)) return 0;
		else return 1;
	}
	return 0;
}
int main() {
	int t; cin >> t;
	for (int  tc = 1; tc <=t; tc++) {
		int n; cin >> n;
		//cin.ignore();
		cin >> l1 >> l2;
		//getline(cin, l1);
		//getline(cin, l2);
		int res = 0;
		fir = false;
		sec= false;

		int fl = -1;
		int sl = -1;
		for (int i = 0; i < n; i++) {
			if ((l1[i] != 'X') && (l2[i] != 'X')) continue;
			if (l1.at(i) == 'X') {
				res +=calg(fl, i, true);
				fl = i;
				fir = false;
			} 
			if (l2.at(i) == 'X') {
				res +=calg(sl, i, false);
				sl = i;
				sec = false;
			}
		}
		// last case
		res += calg(fl,n,true);
		res += calg(sl,n,false);

		cout << "Case #" << tc << ": " << res << "\n";
	}	
	return 0;
}
