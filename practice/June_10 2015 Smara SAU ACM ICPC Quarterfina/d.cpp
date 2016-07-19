#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long lls;
map<lls,int> m;
vector<lls> arr;
int main() {
  int n; cin >>n;
  m[0] = -1;
  for (int i =0; i <n; i++) {
    lls tm; cin>>tm;
    arr.push_back(tm);
  }
  int mm = 0x3f3f3f3f;
  vector<int> res;
  for(int i =0; i <n; i++) {
    if (i !=0) arr[i] +=arr[i-1];
   if (m.find(arr[i]) != m.end()) {
     lls ll = arr[i];
    if (i -m[ll] < mm) {
    //  cout << i << " " << ll << " " << mm << endl;
      res.clear();
      res.push_back(m[ll] +1);
      res.push_back( i -m[ll]);
    } else if (i - m[ll] == mm) {
      
      res.push_back(m[ll] +1);
      res.push_back( i -m[ll]);
    }
    mm = min (mm, i - m[ll]);
   } 
   m[arr[i]] = i;
  }

  if (mm == 0x3f3f3f3f) {
    cout << -1 << endl;
    return 0;
  }
    cout << res[0] +1 << " " << res[1] << endl;
}