#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<limits>
using namespace std;

const int INF=numeric_limits<int>::max();

int main() {
  int t; cin >> t;
  while (t--) {
unordered_map<char, vector<int>> om;
    string s; cin >> s;
    for (int i=0; i<s.size(); i++) {
      om[s[i]].push_back(i);
    }
    int res=INF;
    int init=om['p'][0];
    int cnt=1;
    for (int i=0; i<om['p'].size(); i++) {
      auto ita =upper_bound(om['a'].begin(), om['a'].end(), init);
      if(ita==om['a'].end()) break;
      auto itt =upper_bound(om['t'].begin(), om['t'].end(), *ita);
      if(itt==om['t'].end()) break;
      auto ith =upper_bound(om['h'].begin(), om['h'].end(), *itt);
      if(ith==om['h'].end()) break;
      res=min(res,*ith-init+1);
      init=om['p'][cnt++];
    }
    if (res==INF) cout << -1 << endl;
    else cout << res << endl;
  }
}
