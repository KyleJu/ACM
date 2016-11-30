#include <bits/stdtr1c++.h>

using namespace std;

int n;
vector<string> v;

int return_num(string x) {
  char f = x[0];
  int fn = f - '0';
  if (fn >= 0 && f <= 9)
    return fn;
  if (f == 'T')
    return 11;
  if (f == 'J')
    return 11;
  if (f == 'Q')
    return 12;
  if (f == 'K')
    return 13;
  if (f == 'A')
    return 14;
}

bool cmp(string a, string b, vector<char> &su, int mask) {
  char suit_a = a[a.length()-1];
  char suit_b = b[b.length()-1];
  int num_a = return_num(a), num_b = return_num(b); 
  int a_idx = find(su.begin(), su.end(), suit_a) - su.begin();
  int b_idx = find(su.begin(), su.end(), suit_b) - su.begin();
  if (a_idx < b_idx)
    return false;
  if (a_idx > b_idx)
    return true;
  // both suits are same, compare mask
  bool ascending = ((mask & (1 << a_idx)) != 0);
  if (ascending && num_a > num_b)
    return true;
  if (!ascending && num_a < num_b)
    return true;
  return false;
}

int lis(vector<char> &su, int mask) {
  vector<int> len(n);
  len.assign(n, -1);
  len[0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i-1; j >= 0; j--) {
      // true if v[i] is greater than v[j]
      if (cmp(v[i], v[j], su, mask)) {
        len[i] = max(len[i], 1 + len[j]);
      }
    }
  }
  return *max_element(len.begin(), len.end());
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<char> suit = {'c', 'd', 'h', 's'};
  int mx = -2;
  do {
    // If i'th bit is on, then i'th suit is ascending
    int mask = 1<<4;
    for (int i =0; i < mask; i++) {
      int res = lis(suit, i);
      mx = max(mx, res);
    }
  } while (next_permutation(suit.begin(), suit.end()));
  cout << n - mx << endl;
}
