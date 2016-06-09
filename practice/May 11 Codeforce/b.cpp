#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n; cin >>n;
	string s; cin>>s;
	int ar[26];
	memset(ar, 0, sizeof ar);
	int bs = 'a';
	int res = 0;
	int ct = 0;
	for(int i = 0; i < n; i++){
		char cur = s[i];
		int num = (int)cur - bs;
		if (ar[num]){
			res++;
		 } else {
		 	ar[num]++;
			ct++;
		 }
	}
	if (res <= 26 - ct) cout <<res;
	else cout << -1;
}
