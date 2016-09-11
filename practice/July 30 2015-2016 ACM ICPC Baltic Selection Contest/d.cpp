#include <bits/stdtr1c++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 505;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, a, b;
//int dist[N][N];
bool town[N][N];
string grid[N];
/*
struct cmp {
  bool operator()(const pii &a, const pii &b) {
    if (dist[a.first][a.second] == dist[b.first][b.second]) {
      if (a.first == b.first)
        return a.second < b.second;
      else
        return a.first < b.first;
    }
    else
      return dist[a.first][a.second] < dist[b.first][b.second];
  }
};
*/
bool seen[N][N];

void bfs(int x, int y, bool is_town) {
  queue<pii> q;
  town[x][y] = is_town;
  q.push({x,y});
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    seen[u.first][u.second] = true;
    for (int i = 0; i < 4; i++) {
      int nx, ny;
      nx = u.first + dx[i];
      ny = u.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == '#' || seen[nx][ny])
        continue;
      town[nx][ny] = !town[u.first][u.second];
      q.push(make_pair(nx,ny));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> a >> b;
  for (int i = 0; i < m; ++i)
    cin >> grid[i];
  //memset(dist, 0x3f3f3f3f, sizeof dist);
  memset(town, 0, sizeof town);
  memset(seen, 0, sizeof seen);
  //bfs(0,0,true);
  //set<pii, cmp> s;
  //pii start = {0,0};
  //pii end = {m-1, n-1};
  //dist[0][0] = 0;
  town[0][0] = true;
  priority_queue<piii, vector<piii>, greater<piii>> pq;
  pq.push(make_pair(0,make_pair(0,0)));
  while(!pq.empty()) {
    piii cur = pq.top();
    pq.pop();
    if ( seen[cur.second.first][cur.second.second]) continue;
    seen[cur.second.first][cur.second.second] = true;
    if ( cur.second.first == m-1 && cur.second.second == n-1) {
      cout << cur.first << endl;
      break;
    }
    int x,y;
    for(int i = 0; i < 4; i++) {
      x = cur.second.first + dx[i];
      y = cur.second.second  + dy[i];
      if (x  < 0  || y < 0 || x >= m || y >= n || grid[x][y] == '#') continue;
      town[x][y] = !town[cur.second.first][cur.second.second];
      if (town[cur.second.first][cur.second.second] && !town[x][y])
        pq.push(make_pair(cur.first +b, make_pair(x,y)));
      else if (!town[cur.second.first][cur.second.second] && town[x][y])

        pq.push(make_pair(cur.first +a, make_pair(x,y)));
    }
  }

  // s.insert(start);
  // while (!s.empty()) {
  //   auto v = *s.begin();
  //   s.erase(s.begin());
  //   int x, y;
  //   for (int i = 0; i < 4; i++) {
  //     x = v.first + dx[i];
  //     y = v.second + dy[i];
  //     if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '#') continue;
  //     int d = dist[v.first][v.second];
  //     if (town[v.first][v.second] && !town[x][y])
  //       d += b;
  //     else if (!town[v.first][v.second] && town[x][y])
  //       d += a;
  //     if (d < dist[x][y]) {
  //       s.erase({x,y});
  //       dist[x][y] = d;
  //       s.insert({x,y});
  //     }
  //   }
  // }
 //  if (dist[m-1][n-1] == 0x3f3f3f3f)
 //    cout << "IMPOSSIBLE" << endl;
 //  else
 //    cout << dist[m-1][n-1] << endl;

  if (!seen[m-1][n-1]) cout << "IMPOSSIBLE" << endl;

}
