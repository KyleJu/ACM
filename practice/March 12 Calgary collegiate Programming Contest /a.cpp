#include<bits/stdtr1c++.h>
using namespace std;

const int N = 20005;

set<int> se;
vector<int> adj[N];
bool seen[N];

void dfs(int x) {
    seen[x] = true;
    for (auto u : adj[x]) {
        if (seen[u] == false)
            dfs(u);
    }
}

int main(){
    int ts; cin>>ts;
    while(ts--){
        int n; cin >>n;
        for (int i=0; i<N; i++)
            adj[i].clear();
        for (int i=0; i<N; i++)
            seen[i] = false;
        for (int i=1; i<=n; i++) {
            string c; cin >> c;
            int line = 0;
            if (c != "NOP")
                cin >> line;
            if (c == "NOP")
                adj[i].push_back(i+1);
            if (c== "GOTO") {
                adj[i].push_back(line);
            }
            else {
                adj[i].push_back(line);
                if (i!=n)
                adj[i].push_back(i+1);
            }
        }

        dfs(1);
        for (int i=1; i<=n; i++) {
            if (seen[i] == true)
                cout << "yes";
            else
                cout << "no";
            if (i!=n)
                cout << endl;
        }    
        cout << endl;
    }
}
