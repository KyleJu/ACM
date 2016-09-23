#include<iostream>
#include<string>
using namespace std;

int main() {
	string s; cin >>s;
	string res;
	int i = 0;
	while( i < s.length() && s[i] == 'a') {
		res += 'a';
		i++;
	}
	bool sss = false;
	for(; i < s.length(); i++) {
		if(s[i] == 'a') break;
		char c = s[i];
		char rr = (char) ((int)c - 1);
		res +=rr;
		sss = true;
	}
	for(;i<s.length(); i++) {
		res +=s[i];
	}
	if (!sss) {
		res = res.substr(0,res.length()-1);
		res += 'z';
	}
	cout << res <<"\n";
}
