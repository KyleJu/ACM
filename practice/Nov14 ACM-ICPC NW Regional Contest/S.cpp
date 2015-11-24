//D2UBC&
#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxN=3e5+5;

int n;
struct surf {
  int end,fun,start;  
};
surf arr[maxN];
ll ends11[maxN];
ll memo[maxN];

bool cmp_e (const surf &a, const surf &b) {
  return a.end < b.end;
}

bool cmp_2 (const int &a, const int &b) {
  return arr[a].end < arr[b].end;
}
int f(int l, int r, int x) {
  while (l<=r) {
  int mid=(l+r)/2;
    if (ends11[mid]==x) return mid;
    if (ends11[mid]<x) l=mid+1;
    else r=mid-1;
  }
  return -1;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    int m,f,w; cin >> m >> f >> w;
    arr[i].fun=f;
    arr[i].start=m;
    arr[i].end=m+w;
  }
  sort(arr,arr+n,cmp_e);
  for (int i=0; i<n; i++)
    ends11[i]=arr[i].end;
  for(int i=0; i<n;i++) {
    //    cout << arr[i].end << " " << arr[i].start << " "<<arr[i].fun << endl;
    //    cout << ends11[i] << " " << arr[i].fun << endl;
  }
  //sort(ends11, ends11+n, cmp_2);
  memo[0]=arr[0].fun;
  for (int i=1; i<n; i++) {
    memo[i]=memo[i-1];
    auto k=lower_bound(ends11, ends11+n, arr[i].start);
    //if (k-ends11 == i) k--;
    if (k==ends11+n || ends11[k-ends11]>arr[i].start) {
      if (arr[i].fun>memo[i]) memo[i]=arr[i].fun;
      continue;
    }
    // int idx=f(0,n-1,arr[i].start);
    // if (idx==-1) {
    //   cout << "III "  << i << endl;
    //   if (arr[i].fun>memo[i]) {
    // 	memo[i]=arr[i].fun; continue;
    //   }
    // }
    //memo[i]=max(memo[i], arr[i].fun+memo[idx]);
        memo[i]=max(memo[i], arr[i].fun+memo[k-ends11]);
  }
  // for (int i=0; i<n; i++)
  //   cout << memo[i] << " ";
  cout << *max_element(memo, memo+n) << endl;
}
