#include<bits/stdtr1c++.h>
 
using namespace std;
 
 
int main() {
  int cur, des; cin >> cur >> des;  
  int res = 0;
  if (cur > des) {
    res = min(cur - des, des+360-cur);
    if(res == cur - des) {
      res = -1*res;
    }
  } else {
    int tm = min(des - cur, cur+360-des);
    if (tm == cur+360-des) {
      res = tm*-1;
    }
    else {
      res = des - cur;
    }
  }
  if(res == -180) cout << 180 << endl;
  else cout << res << endl;
}
