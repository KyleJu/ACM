#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
typedef long long ll;

const int INF=numeric_limits<int>::max();

int n, k;
int arr[4005][4005];
int memo[805][4005];
ll cost[4005][4005];

void fn() {
    memset(cost, 0, sizeof cost);
    for (int i=0; i<n; i++) {
        cost[i][0]=cost[i-1][0]+arr[i][0];
        cost[0][i]=cost[0][i-1]+arr[0][i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cost[i][j]=cost[i-1][j]+cost[i][j-1]-cost[i-1][j-1]+arr[i][j];
        }
    }
}

ll eval(int l, int r) {
    if (l==0) return cost[r][r]/2;
    else return (cost[r][r]-cost[r][l-1]-cost[l-1][r]+cost[l-1][l-1])/2;
}

void compute(int d, int l, int r, int optl, int optr) {
    if (r<l) return;
    int m=(l+r)/2;
    ll ans = INF;
    int opt=0;
    for (int i=max(optl,m); i<=optr; i++) {
        if (memo[d-1][i+1] + eval(m,i) < ans) {
            ans=memo[d-1][i+1] + eval(m,i);
            opt=i;
        }
    }
    memo[d][m]=ans;
    compute(d,l,m-1,optl,opt);
    compute(d,m+1,r,opt,optr);
}

int main() {
    //ios_base::sync_with_stdio(0);
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char ch;
            while(isspace(ch=getchar()));
            arr[i][j]=ch-'0';
        }
    }
    fn();
    for (int i=0; i<n; i++)
        memo[0][i]=INF;
    for (int i=1; i<=k; i++)
        compute(i,0,n-1,0,n-1);
    printf("%d\n",memo[k][0]);
}
