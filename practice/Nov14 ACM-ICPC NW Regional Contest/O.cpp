#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
#include<limits>
#include<string>
using namespace std;
typedef pair<int, int> pii;
const int INF=numeric_limits<int>::max();

int dist[505][505];
int grid[505][505];

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

int main() {
  for (int i=0; i<505; i++) {
    for (int j=0; j<505; j++) {
      dist[i][j]=INF;
    }
  }
  int m, n;  cin >> m >> n;
  for (int i=0; i<m; i++) {
    string s; cin >> s;
    for (int j=0; j<n; j++) {
      grid[i][j]=s[j]-'0';
    }
  }
  queue<pii> q;
  dist[0][0]=0;
  q.push(make_pair(0,0));
  while (!q.empty()) {
    pii pt = q.front(); q.pop();
    if (pt.first<0 || pt.first>=m || pt.second<0 || pt.second>=n) continue;
    for (int i=0; i<4; i++) {
      pii ne = make_pair(pt.first+dx[i]*grid[pt.first][pt.second], pt.second+dy[i]*grid[pt.first][pt.second]);
      if (ne.first<0 || ne.first>=m || ne.second<0 || ne.second>=n) continue;
      if (dist[ne.first][ne.second]!=INF) continue;
      dist[ne.first][ne.second]=1+dist[pt.first][pt.second];
      q.push(ne);
    }
  }
  if (dist[m-1][n-1]==INF) cout << "IMPOSSIBLE";
  else cout << dist[m-1][n-1];
  cout << endl;
}
