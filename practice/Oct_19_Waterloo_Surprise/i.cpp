#include<bits/stdtr1c++.h>
 
using namespace std;
bool head[100005];
bool vis[100005];
vector<int> adjs[100005];
vector<int> adj2[100005];
 
void dfs2(int cur) {
    vis[cur] = true;
    for(auto n: adj2[cur]) {
        if(vis[n]) continue;
        dfs2(n);
    }
}
void dfs(int cur) {
    vis[cur] = true;
    for(auto n: adjs[cur]) {
        if(vis[n]) continue;
        dfs(n);
    }
}
int main() {
    int t; cin >> t;
    for(int ts = 0; ts < t; ts++) {
        int n, m; cin >> n >> m;
        int l,r;
        for (int i = 0; i < 100005; i++) {
            adjs[i].clear();
            adj2[i].clear();
        }
        memset(head, 0 ,sizeof head);
        memset(vis, 0 , sizeof vis);
        int res = 0;
        for(int i = 0; i < m; i++) {
            cin >> l >> r;
            adjs[l].push_back(r);
            adj2[l].push_back(r);
            adj2[r].push_back(l);
            if(!head[r]) {
                head[r] = true;
            }        
        }
        for(int i  =1;  i <= n; i++) {
            if(vis[i]) continue;
            if(head[i]) continue;
            dfs(i);
            res++;
        }
        for(int i = 1; i <=n; i++) {
            if(!vis[i]) {
                res++; dfs2(i);
            }
        }
        cout << res << endl;
    }
}
