#include<bits/stdtr1c++.h>

using namespace std;
typedef __int128 inn;

int main() {
	inn a1,a2,a3,a4;
	cin >> a1 >> a2 >> a3 >> a4;
	string res;
	while(a1) {
		if(a2 > a1) {
		//0
			a2 = a2 -a1;
			res = "1" + res;
		} else {
			//1 	
			a1 = a1 - a2;
			res = "0" +res;
		}
	}
	cout <<res << endl;
}
