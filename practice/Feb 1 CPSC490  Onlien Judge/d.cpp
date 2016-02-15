#include<iostream>
#include<vector>
//res = (res + ar[i][j]) %49031337;
// careful when you do mod!!! 
// use brackets!!!!
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
vii a  {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1}, 
		{1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0}, 
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0}, 
		{1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0}, 
		{1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, 
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0}, 
		{1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1}, 
		{1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0}, 
		{1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0}, 
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}};
//0b00000, 0b00001, 0b00010, 0b00100, 0b01000, 0b10000, 0b00101, 0b01001, 0b10001, 0b01010, 0b10010, 0b10100, 0b10101
vii matrix(const vii& f, const vii& s) {
	vii res;
	for (int i =0; i < 13; i++) {
		vi temp;
		for (int j = 0; j <13; j++) {
			ll sum = 0;
			for (int z = 0; z <13;z++){
				sum = (sum + f[z][j]*s[i][z]) %49031337;
			}
			temp.push_back(sum);
		}
		res.push_back(temp);
	}
	return res;
}

vii pow(ll n) {
	if (n <= 1) return a;
	if ((n%2)==1) {
		return matrix(a, pow(n-1));
	}
	vii temp = pow(n/2);
	vii res = matrix(temp, temp);
	return res;

}
ll mat(ll n) {
	if (n<0) return 0;
	if(n ==0) return 13;
	vii ar = pow(n);
	ll res = 0;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j ++){
			//sum of 
			res = (res + ar[i][j]) %49031337;
		}
	}
	return res;
}
int main() {
	int t; cin >>t;
	while (t--) {
		ll n; cin >>n;
		ll res = mat(n-1);
		cout << res << "\n";
	}
}