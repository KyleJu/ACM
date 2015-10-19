#include<iostream>

#define ll long long

using namespace std;

int main(void) {
  int T; cin>>T;
  while(T--) {
    ll N;cin>>N;
    ll i=1;
    ll sum=0;
    for(i=1;sum<N;i++) {
      ll t=((i*i)+i)/2;
      sum+=t;
    }
    i--;
    ll ans=0;
    for(;N>0;i--) {
      N-=(i*i+ i)/2;
      ans++;
    }
    cout << ans << endl; 
  }
}
