#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> ar;
int main() {
  int n; cin >>n;
    for(int i = 0; i < n; i ++) {
      ll tm; cin >>tm;
      ar.push_back(tm);
  }
    sort(ar.begin(), ar.end());
    int res = 0;
    for(int i = 0; i <n ;i++) {
      if (ar[i] <=i) {
        res = i+1;
      }
    }

    cout << res << endl;

}