#include<iostream>

using namespace std;

int t;
int m, n;

bool edges[16][16]
long long memo[1<<16][16], memo2[1<<16][16];

long long dp(int s, int k) {
    if (s==0) return 1;
    if (k==0) return 0;
    if (memo[s][k] != -1)
        return memo[s][k];
    long long res = dp(s,k-1);;
    for (int i=0; i<n; i++) {
        if ((s&(1<<i)) != 1) continue;
        if (edges[i][k])
            res += dp((s-(1<<i)),k-1);
    }
    return res;
}


long long dp2(int s, int k) {
    if (s==0) return 1;
    if (k==0) return 0;
    if (memo2[s][k] != -1)
        return memo2[s][k];
    long long res = dp(s,k-1);;
    for (int i=0; i<n-2; i++) {
        if ((s&(1<<i)) != 1) continue;
        if (edges[i][k])
            res += dp((s-(1<<i)),k-1);
    }
    return res;
}

int main(void) {
    cin >> t;
    while(t--) {
     cin >> n >> m;
        for(int i=0; i<16; i++) {
            for(int j=0; j<16; j++) {
                if(i == j) {
                    edges[i][j] = 0;
                } else {
                    edges[i][j] = 1;
                }
            }
        }
        for(int i=0; i<m; i++) {
            int u,v; cin >> u >> v;
            edges[u][v] = 0;
            edges[v][u] = 0;
        }

        memset(memo, -1, sizeof memo);
        memset(memo, -1, sizeof memo);
        
        long long total = dp(((1<<n)-1), n);
        long long x = dp2(((1<<(n-2))-1), n-2);
        
    }
    return 0;
}
