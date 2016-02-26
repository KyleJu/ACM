#include <bits/stdtr1c++.h>
using namespace std;
#define ll long long 
//625
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3
//e o e o e e o e o e e o e o e e o e o e e o e o e 
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3
//o e o e o o e o e o o e o e o o e o e o o e o e o
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3
//e o e o e e o e o e e o e o e e o e o e e o e o e 
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3
//o e o e o o e o e o o e o e o o e o e o o e o e o
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 4 - 5*5^3
//e o e o e e o e o e e o e o e e o e o e e o e o e 
// even k, same repeating ***
//1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3
//e o e o e e o e o e e o e o e e o e o e e o e o e 

// By Observation:
// swtich every inside every 5^k, it is repeating the same pattern
// until 5^(k+1) appears
// also since switching k and k+1 is different parity
// given the pattern of k, you can find the pattern of k+1
// if k is even (e.g. 2,4) it is repeating the same pattern
// if k is odd, for the next 4 line, 1 3 are totally opposite
// 2 and 4 are the same 
// k is odd : 5* res[k-1]    even : 3*res[k-1] + 2*(total num in k-1 - res[k-1])

ll sum[28];
ll a[28];
int main() {
	ll n;
	sum[1] = 1;
	sum[2] = 3;
	a[0] = 1;
	for (int i = 1; i < 28; i++) {
		a[i] = a[i-1]*5;
	}
	for(int i = 3; i<28; i++) {
		if (i%2) sum[i] = 5*sum[i-1];
		else sum[i] = 3*sum[i-1] + 2*(a[i-2] - sum[i-1]);
	}
	while (cin >>n) {
		if (n == -1) break;
			ll res = 0; int flag = 0; //10101 or 01010 current pattern
			if (n<=4) {
				cout << n+1 << "\n";
				continue;
			}
			n++;
			while(n){ 
				// binary to find the closet power of 5 
				int k=upper_bound(a,a+28,n) - a; 
				//cout << k << " " << n << " " << a[3]<< "\n"; 
				k--;  
				if(k == 0){  
					if(flag == 0)  
						res+=n;  
					break;  
				}
				// largest pattern  
				ll x= n/a[k];  
				n-=a[k]*x;   
				if(k&1){  
					if(x%2){  
						int a1=x/2,a2=(x+1)/2;   
						if(!flag)  res+=a2*sum[k]*5+a1*(a[k-1]-sum[k])*5;  
						else  res+=a1*sum[k]*5+a2*(a[k-1]-sum[k])*5;  
					} else  
					res+=x/2*a[k-1]*5;  
				}else{  
					if(flag == 0)  res+=sum[k]*x*5;  
					else  res+=(a[k-1]-sum[k])*x*5;  
				}
				// odd and the even line of odd k will change the pattern  
				if((k&1) && (x%2 !=0)) flag^=1;  
			}
			cout << res << "\n";
		}
		return 0;
	}