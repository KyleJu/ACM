#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int grid[2005][2005];
int res[2005][2005];

int main() {
  int t; cin >> t;
  while (t--) {
    memset(grid,-1,sizeof grid);
    memset(res,-1,sizeof res);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
      string s; cin >> s;
      for (int j=0; j<n; j++) {
	char ch; ch=s[j];
	if (ch=='E') grid[i][j]=1;
	if (ch=='F') grid[i][j]=0;
	res[i][j]=grid[i][j];
      }
    }
    int ans=0;
    for (int i=1; i<n; i++) {
      for (int j=1; j<n; j++) {
	if (grid[i][j]==0) { continue; }
	res[i][j]=1+min(res[i-1][j], min(res[i][j-1], res[i-1][j-1]));
	ans=max(ans,res[i][j]);
      }
    }
    cout << ans << endl;

  }
}
