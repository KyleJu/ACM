#include<bits/stdtr1c++.h>

using namespace std;
// Diophatine
// a1x1+a2x2+a3x3=c -> gcd(a1,a2)y+a3x3=c -> gcd(a1,a2,a3) | c
// true for all coefficients
// but this question is asking for positive non-negative coe
// thus setting a threshold

// Note: diopantine solver is for non-negative coe
// extendted euclide for all coe
// using canonical egcd for non-negative
// threshold: two relatively prime positive integers $m,n$, the greatest integer that cannot be written in the form $am + bn$ for nonnegative integers a, b is mn-m-n.
int n;
typedef long long ll;
ll k;
int arr[21];
bool ch[(int)1e6+5];
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];	
	}
	if(k >=1e6) {
		int gg = arr[0];
		for(int i = 1; i <n;i++) gg = __gcd(gg, arr[i]);
		if(k%gg ==0) cout <<"possible" << endl;
		else cout <<"impossible" <<endl;
	}else {
		ch[0] =1;
		for(int i = 0; i<n; i++) {
			for(int j = (int)1e6; j>=0; j--) {
				if(ch[j]) ch[j+arr[i]] = true;	
			}
		}
		if(ch[k]) cout << "possible" << endl;
		else cout <<"impossible" << endl;
	}
}
