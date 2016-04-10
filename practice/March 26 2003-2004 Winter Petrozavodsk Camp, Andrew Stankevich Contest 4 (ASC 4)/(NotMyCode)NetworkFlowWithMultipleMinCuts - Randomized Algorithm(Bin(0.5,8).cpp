#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 805, M = 20005;
// data structures and helper functions common to all flow routines
int par[N], first[N], nxt[2*M], ep[2*M], m;
ll flo[2*M], cap[2*M];
void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
  nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, ++m;
  nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, ++m; }

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
    
struct edge {
	int u, v, w;
} edge[10005];

const ll C = 1e4;

int main() {
	ios::sync_with_stdio(0);
	srand(420);
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	
	int N, M, s, t;
	scanf("%d%d%d%d", &N, &M, &s, &t);
	s--, t--;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		edge[i].u--;
		edge[i].v--;
	}
	
	vector<int> cut[2];
	bool any_ambig = false;
	int iter = (N > 500 ? 4 : 8);
	while (iter--) {
		cut[0].clear();
		cut[1].clear();
	
		init();
		int maxW = 0;
		for (int i = 0; i < M; i++) {
			ll cap = C * edge[i].w + (rand()%2 ? 1 : -1);
			add_edge(edge[i].u, edge[i].v, cap);
			add_edge(edge[i].v, edge[i].u, cap);
			maxW = max(maxW, cap);
		}
	
		ll flow0=0;
		for (ll del=maxW; del; del/=2) while (ll df=mf_update(s, t, del)) flow0+=df;

		for (int e = 0; e < m; ++e)
		if (par[ep[e]] != -1 && par[ep[e^1]] == -1) cut[0].push_back(e);
	
		// TROLLLOLOLOLOLOLOLOLOL
		// REPEAT
		init();
		maxW = 0;
		for (int i = 0; i < M; i++) {
			ll cap = C * edge[i].w + (rand()%2 ? 1 : -1);
			add_edge(edge[i].u, edge[i].v, cap);
			add_edge(edge[i].v, edge[i].u, cap);
			maxW = max(maxW, cap);
		}
	
		ll flow1=0;
		for (ll del=maxW; del; del/=2) while (ll df=mf_update(s, t, del)) flow1+=df;

		for (int e = 0; e < m; ++e)
		if (par[ep[e]] != -1 && par[ep[e^1]] == -1) cut[1].push_back(e);
	
		sort(cut[0].begin(), cut[0].end());
		sort(cut[1].begin(), cut[1].end());

		if (cut[0].size() != cut[1].size()) any_ambig = true;
		else {
			bool ambig = false;
			for (int i = 0; i < cut[0].size(); i++) {
				if (cut[0][i] != cut[1][i]) {
					ambig = true;
					break;
				}
			}
			
			any_ambig |= ambig;
		}
		
		if (any_ambig) break;
	}
	
	cout << (any_ambig ? "AMBIGUOUS" : "UNIQUE") << endl;
	return 0;
}