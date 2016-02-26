#include <bits/stdtr1c++.h>
//mistakes: int divide by int always floor
// if use ceil, cast it first!!
// const int using & means don't allocate memory for it

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll INF = 0x3f3f3f3f; 
const int N = 250;
const int M = 250*250;

//M number of edges
//N number of nodes

int par[N], first[N], nxt[2*M], ep[2*M], m;
ll flo[2*M], cap[2*M], cost[2*M];
void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
  nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m] =  p, ++m;
  nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m] = -p, ++m; }
  
// Max flow without costs, USAGE: 1) init(); 2) add edges, 3) ll flow=0; and 4)
// for (ll del=INF; del; del/=2) while (ll df=mf_update(s, t, del)) flow+=df;
// Then if you want to extract a min cut: for (int e = 0; e < m; ++e)
// if (par[ep[e]] != -1 && par[ep[e^1]] == -1) cut.push_back(e);
// If you want to recover flow paths: get set of edges with flo[e] > 0.
// E^2logC in general, E*flow on integer capacity graphs
ll mf_update(int s, int t, ll del=1) {
  ll df[N]; memset(df, 0, sizeof df); memset(par, -1, sizeof par);
  queue<int> q; q.push(s); par[s] = -2; df[s] = INF;
  while (!q.empty()) { ll cf; int u = q.front(); q.pop();
    for (int v, e = first[u]; e != -1; e = nxt[e])
      if (par[v=ep[e^1]] == -1 && (cf = cap[e]-flo[e]) >= del)
        q.push(v), par[v] = e, df[v] = min(df[u], cf); }
  if (par[t] == -1) return 0;
  for (int e, i = t; i != s; i = ep[e])
    e = par[i], flo[e] += df[t], flo[e^1] -= df[t];
  return df[t]; }

// max flow is pushing the number of reusable classrooms
  ll solve() {
    ll n, m; cin>> n >>m;
    init();
    vl ss, ee, caps;
    // n to n matching, set source as 2n+1
    ll source  = 2*n;
    ll sink = 2*n+1;
    ll iCaps = 0;
    for(int i = 0; i < n; i++) {
      ll s, e, num; cin>> s >> e >> num;
      //ll cap = ceil(num/m);
      ll cap = (num-1)/m +1;
      ss.push_back(s); ee.push_back(e); caps.push_back(cap);
      iCaps += cap;
      //2 i on the left  2i +1 on the right
      add_edge(source, 2*i, cap);
      add_edge(2*i +1, sink, cap);
      //cout << source <<" " << 2*i << " " << cap << " " << num << " " << m <<  " " << ceil(num/m) << "\n"; 
    }
    for (int i = 0; i<n; i++) {
      for (int j = 0; j<n; j++) {
        ll cl; cin>> cl;
        if (i == j) continue;
        // where does it say it cannot schedule if the time fit exactly????
        if (ee[i] + cl >= ss[j]) continue;
        add_edge(2*i, 2*j+1, INF);
      }
    }
    ll flow= 0;
    for (ll del=INF; del; del/=2) while (ll df=mf_update(source, sink, del)) flow+=df;
      // icap = 2*flow + y (not reusable)   flow + y = icap - flow = ans;
    return iCaps - flow;
  }

int main(){
	ios::sync_with_stdio(0);
	int t; cin >>t;
	for (int i = 1; i <=t; i++) {
		ll res = solve();
		cout << "Case " << i  << ": " << res << "\n";
	}
}