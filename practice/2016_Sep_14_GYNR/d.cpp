#include<bits/stdtr1c++.h>

using namespace std;

long long cn[10005];
void si(int n) {
	for(int i =0; i <= n; i++) cn[i] = i;
	for(int i = 2; i <=n; i++) {
		if(i == cn[i])
		for(int j = i; j <=n; j+=i) cn[j] = (cn[j]/i) *(i-1);
	}
}
int main() {
	int ts; cin >> ts;
	int k,n;
	si(10000);	
	for(int i = 1; i <=10000; i++) cn[i] = cn[i-1] +cn[i];
	for(int i = 0; i < ts; i++) {
		cin >> k >> n;
		cout << k << " " << cn[n] +1 << endl;
	}
}
