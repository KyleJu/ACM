#include<iostream>

using namespace std;

int main(){
	string a,b,c,d; cin >>a >> b >> c>>d;
	string res,res1;
	for(int i = 0; i <2; i++){
		if (a[i] != 'X')
		res += a[i];
		if (c[i] != 'X')
		res1 += c[i];
	}
	for(int i = 0; i <2; i++){
		if (b[1-i] != 'X')
		res += b[1-i];
		if (d[1-i] != 'X')
		res1 += d[1-i];
	}

	for(int i = 0; i < 3; i ++) {
		if (res[0] == res1[i%3] && res[1] == res1[(i+1)%3]) {
			cout << "YES" << "\n";
			return 0;
		}
	}

	cout << "NO" <<"\n";



}