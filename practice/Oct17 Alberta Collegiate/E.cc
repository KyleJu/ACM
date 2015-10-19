#include<iostream>
#include<limits>

using namespace std;

int P[100005];
double dp[100005][100005];

int n,k;
int main(void) {
  int T; cin>>T;
  while(T--) {
    cin>>n>>k;
    for(int i=0;i<100005;i++) {
      for(int k=0;k<100005;k++) {
	for(int j=0;j<100005;j++) {
	  //dp[i][j][k]=numeric_limits<int>::max();
	}
      }
    }
    for(int i=1; i<=n; i++) {
      cin>>P[i];
    }
    for(int i=1;i<=n;i++) {
      //      dp[i][i]=
    }
    for(int l=1;l<=n;l++) {
      
      for(int i=l;i<n-l+1;i++) {
	//int min=numeric_limits<int>::max();
	//	for(int 
      }
      
    }
  }
}
