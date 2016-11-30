#include<bits/stdtr1c++.h>
 
using namespace std;
const int N = 200005;
vector<int> adjs[N];
int leftt[N];
int cn[N];
bool vis[N];
int main() {
    int c,p,x,l; cin >> c >> p >> x >> l;
    int a,b;
    for(int i = 0; i < p; i++) {
        cin >> a >>b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    for(int i = 1; i <= c; i++) {
        cn[i] = adjs[i].size();
    }
    queue<int> que;
    que.push(l);
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        for(auto v: adjs[cur]) {
            leftt[v]++;
            if(leftt[v]*2 >= cn[v]) que.push(v);
        }
 
    }
    if(vis[x]) cout << "leave" << endl;
    else cout << "stay" << endl;
     
}
