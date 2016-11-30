#include<bits/stdtr1c++.h>

using namespace std;

typedef pair<int, int> pii;

struct die {
  // top, bottom, left, right, forward, backward
  int t, b, l, r, f, ba;
  die() {}
  die(int s1, int s2, int s3, int s4, int s5, int s6)
    : t(s1), b(s2), l(s3), r(s4), f(s5), ba(s6) {}
};

int n;
vector<string> m;
bool seen[20][20][7][7];

char direction[] = {'r', 'u', 'l', 'd'};
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

die move_dice(die d, char dir) {
  struct die ans = die();
  if (dir == 'l') {
    ans.b = d.l;
    ans.r = d.b;
    ans.f = d.f;
    ans.ba = d.ba;
    ans.t = d.r;
    ans.l = d.t;
  } else if (dir == 'r') {
    ans.b = d.r;
    ans.r = d.t;
    ans.f = d.f;
    ans.ba = d.ba;
    ans.t = d.l;
    ans.l = d.b;
  } else if (dir == 'u') {
    ans.b = d.ba;
    ans.r = d.r;
    ans.l = d.l;
    ans.t = d.f;
    ans.f = d.b;
    ans.ba = d.t;
  } else {
    ans.b = d.f;
    ans.r = d.r;
    ans.l = d.l;
    ans.t = d.ba;
    ans.f = d.t;
    ans.ba = d.b;
  }
  return ans;
}


bool dfs(int x, int y, die d) {
  // cout << x << " " << y << " " << d.b << " " << d.r << endl;
  seen[x][y][d.b][d.r] = true;
  if (m[x][y] == 'H' && d.b== 5)
    return true;
  for (int i = 0; i < 4; i++) {
    int nx, ny;
    nx = x+dx[i];
    ny = y+dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n || m[nx][ny] == '*')
      continue;
    die new_dice = move_dice(d, direction[i]);
    if (seen[nx][ny][new_dice.b][new_dice.r])
      continue;
    if (dfs(nx, ny, new_dice))
      return true;
  }
  return false;
}

int main(void) {
  int T; cin >> T;
  while(T--) {
    m.clear();
    memset(seen,0,sizeof seen);
    cin >> n;
    int sx, sy;
    for(int i=0; i<n; i++) {
      string s; cin >>s;
      m.push_back(s);
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(m[i][j] == 'S') {
          sx=i; sy=j; break;
        }
      }
    }
    die start_die = die(1, 6, 5, 2, 3, 4);
    bool res = dfs(sx,sy,start_die);
    string ans = res?"Yes":"No" ;
    cout << ans << endl;
  }
  return 0;
}
