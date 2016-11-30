#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
const int N = 102;
ll nn;
ll sx[102];
ll sy[102];
ll tx[102];
ll ty[102];
bool adjmat[N][N], seen[N]; ll matchL[N], matchR[N], m, n;
bool bpm(ll u) { // Can we find augmenting path starting from u
  for(ll v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) { seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) { matchL[u] = v, matchR[v] = u;
      return true; } }
  return false; }

bool ok(ll mid) { 
memset(matchL,-1,sizeof matchL); memset(matchR,-1,sizeof matchR);
  memset(adjmat, 0, sizeof adjmat);
  for(ll i = 0; i < nn; i++) {
	for(ll j = 0; j < nn; j++) {
		ll c = abs(sx[i] - tx[j]) + abs(sy[i] - ty[j]);
		if(c >mid) continue;
		adjmat[i][j] = 1;
	}
  }
  ll cnt = 0;
  for(ll i = 0; i < m; i++) {
    memset(seen, 0, sizeof seen);
    if( bpm(i) ) cnt++; // matchL[i] is the match
  }
  return cnt == nn;
  	
  }

  
int main() {
	cin >> nn;
	m = nn;n = nn;
	for(ll i = 0; i < nn; i++) {
		cin >> sx[i] >> sy[i];	
	}
	for(ll i = 0; i < nn; i++) {
		cin >> tx[i] >> ty[i];
	}
	ll left = -1, right = 1e9; 
	while(left  + 1 < right) {
		ll mid = left + (right - left)/2;
		if(ok(mid)) right = mid;
		else left = mid;
	}
	if(ok(left)) right = left;
	cout << right << endl;

}
