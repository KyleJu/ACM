#include <bits/stdtr1c++.h>
using namespace std;

int main() {
  long long a,b; cin>> a >> b;
  long long res = 0;
  int len = 0;
  if (a == 0) {
    len = 1;
    cout << abs(a-b) << endl;
    return 0;
  }
  long long tmp = a;
  while (tmp) {
    len++;
    tmp /= 10;
  }
  string ans = "";
  tmp = a;
  while (a) {
    int da = a%10;
    int db = b%10;
    a /= 10;
    b /= 10;
    int t = abs(da-db);
    ans += (t+'0'); 
  }
  reverse(ans.begin(), ans.end());
  string fans = "";
  int pos = 0;
  for (int i = 0; i < ans.size(); i++)
    if (ans[i] == '0') pos++;
    else break;
  if (pos == ans.size()) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = pos; i < ans.size(); i++)
    fans += ans[i];
  cout << fans << endl;
  return 0;
  int lenA = log10(a);
  int lenB = log10(b);
  for(int i = 0; i <= max(lenA,lenB); i++) {
    int x = 0, y = 0;
    if (i <= lenA)
    x = (int)(a/pow(10,i)) %10;
    if(i <= lenB)
    y = (int)(b/pow(10,i))%10;
    int tm = abs(x-y);
    if (!tm) continue;
    res += (tm*pow(10,i));
  }
  cout << res << endl;
}
