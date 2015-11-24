#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[26];

int main() {
  int res=0;
  string s; cin >> s;
  for (auto ch : s) {
    arr[ch-'a']++;
  }
  sort(arr, arr+26);
  for (int i=0; i<24; i++) {
    res+=arr[i];
  }
  cout << res << endl;
}
