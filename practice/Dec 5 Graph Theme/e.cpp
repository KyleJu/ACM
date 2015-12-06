#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<utility>
#include<iomanip>
#include<algorithm>
#include<limits>
using namespace std;
typedef long double ld;
typedef pair<int, ld> pii;

const ld INF=numeric_limits<ld>::min();

int n, m;
vector<pii> adj[105];
ld dist[105];

struct cmp {
    bool operator()(const int& u, const int&v) {
        if (dist[u]==dist[v]) return u>v;
        else return dist[u]>dist[v];
    }
};

ld dijkstra() {
    fill(dist, dist+105, INF);
    dist[0]=1;
    set<int, cmp> s;
    s.insert(0);
    while (!s.empty()) {
        int t=*s.begin();
        s.erase(s.begin());
        for (int i=0; i<adj[t].size(); i++) {
            pii x=adj[t][i];
            int u=x.first; ld w=x.second;
            ld d=dist[t]*w;
            if (d>dist[u]) {
                s.erase(u);
                dist[u]=d;
                s.insert(u);
            }
        } 
    }
    return dist[n-1]*100.0;
}

int main() {
    while (cin >> n) {
        if (n==0) break;
        cin >> m;
        for (int i=0; i<105; i++) adj[i].clear();
        for (int i=0; i<m; i++) {
            int a, b; int p; cin >> a >> b >> p;
            adj[a-1].push_back({b-1,p/100.0});
            adj[b-1].push_back({a-1,p/100.0});
        }
        cout << fixed << setprecision(6) << dijkstra() << " percent" << endl;
    }
}

