#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<limits>
using namespace std;

double table[65][65];
double dp[65][65];
const int INF=numeric_limits<int>::max();

void choose() {
  for (int i=0; i<65; i++)
    table[i][0]=1;
  for (int i=0; i<65; i++)
    table[i][i]=1;
  for (int i=1; i<65; i++) {
    for (int j=1; j<65; j++) {
      if (j>i) table[i][j]=0;
      if (i==j) continue;
      table[i][j] = table[i-1][j] + table[i-1][j-1];
    }
  }
}

int main() {
  choose();
  int t; cin >> t;
  while (t--) {
    int c,b; cin >> c >> b;
    vector<int> vec;
    int n=0;
    for (int i=0; i<c; i++) {
      int x; cin >> x; vec.push_back(x); n+=x; 
    }

    // double den = table[n][b];
    // double num = 1;
    // for(int i=0;i<c;i++) {
    //   num*=table[vec[i]][1];
    // }
    // num*=table[n-c][b-c];
    // double res=num/den;
    memset(dp,0,sizeof dp);
    double res=0.0;
    dp[0][0]=0;
    for (int i=1; i<=b; i++) {
      for (int j=0; j<c; j++) {
	for (int k=1; k<=min(i,vec[j]); k++) {
	  if (j==0) {
	    dp[i][j]+=table[vec[j]][k];
	  }
	  else {
	    dp[i][j]+=(dp[i-k][j-1]*table[vec[j]][k]);
	  }
	}
      }
    }
    res=dp[b][c-1]/table[n][b];
    cout << fixed << setprecision(6) << res << endl;
  }
}

