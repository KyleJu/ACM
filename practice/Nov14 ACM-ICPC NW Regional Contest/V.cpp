#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#define ll long long
#define pii pair<ll,ll>

using namespace std;

struct gear {
  int r,x,y;
};

vector<int> m[1001];
gear g[1001];
int par[1001];
int n;
bool seen[1001];
bool ok(gear a, gear b) {
  return (a.r+b.r)*(b.r+a.r) == ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
ll gcd(long long a, ll b) {
  return b==0 ? a : gcd(b, a%b);
}

void simplify(pii &a) {
  long long tmp=0;
  if(a.first>a.second) {
    tmp=gcd(a.first,a.second);
    a.first/=tmp;
    a.second/=tmp;
  } else {
    tmp=gcd(a.second,a.first);
    a.first/=tmp;
    a.second/=tmp;
  }
}
bool dfs1(int x,int p) {
  if(seen[x]) return true;
  par[x]=p;
  seen[x]=true;
  for(int y:m[x]) {
    if(y==p) continue;
    if(dfs1(y,x)) return true;
  }
  return false;
}

int main(void) {
  cin>>n;
  memset(seen, false, sizeof seen);
  for(int i=0; i<n; i++) {
    int x,y,r; cin>>x>>y>>r;
    g[i].x=x;
    g[i].y=y;
    g[i].r=r;
  }
  for( int i=0; i<n;i++ ) {
    for( int j=i+1; j<n; j++) {
      if(ok(g[i],g[j])) {
	m[i].push_back(j);
	m[j].push_back(i);
      }
    }
  }
  memset(par,-1,sizeof par);
  bool loop=dfs1(0,-1);
  if(loop) { 
    cout << "The input gear cannot move." << endl;
    return 0;
  }
  if(par[n-1]==-1) {
    cout << "The input gear is not connected to the output gear." << endl;
    return 0;
  }
  int res=1;
  int i=n-1;
  pii temp;
  temp.first=1;
  temp.second=1;
  while(par[i]!=0) {
    res++;
    i=par[i];
  }
  temp.first=g[0].r;
  temp.second=g[n-1].r;
  simplify(temp);
  if(res%2==1)
    cout << "-";
  cout << temp.first << ":" << temp.second << endl;
  return 0;
}
