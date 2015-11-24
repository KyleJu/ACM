//D2UBC&
#include<iostream>
#include<utility>
#include<set>
#define pii pair<long long,long long>
#define ll long long
using namespace std;

int w,h,b;
pii arr[105][105];
int dx[]={1,0,-1,0,1,-1,1,-1,0};
int dy[]={0,1,0,-1,1,-1,-1,1,0};
pii tmp[105][105];
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

pii sum(pii &a, pii &b) {
  pii ans;
  ans.second=a.second*b.second;
  ans.first=a.first*b.second + a.second*b.first;
  simplify(ans);
  return ans;
}
int main(void) {
  
  cin>>w>>h>>b;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      int x; cin>>x;
      if(x==1) {
	arr[i][j].first=1;
	arr[i][j].second=1;
      } else {
	arr[i][j].first=0;
	arr[i][j].second=1;     
      }
    }
  }
  
  for(int k=0; k<b; k++) {
    
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
	pii res; res.first=0; res.second=1;
	for(int z=0; z<9; z++) {

	  int x=i+dx[z];
	  int y=j+dy[z];
	  if(x<0) x=h-1;
	  if(y<0) y=w-1;
	  if(y>=w) y=0;
	  if(x>=h) x=0;
	  //cout << res.first<< "/"<<res.second<<"+"<<arr[x][y].first<<"/"<<arr[x][y].second<<" = ";
	  //if(i==0 && j==2)
	    //cout << x << " " << y << endl;
	  res = sum(res,arr[x][y]);
	  //cout << res.first<<"/"<<res.second<<endl;

	}
	res.second*=9;
	simplify(res);
	tmp[i][j].first=res.first;
	tmp[i][j].second=res.second;
      }
    }
    
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
	arr[i][j].first=tmp[i][j].first;
	arr[i][j].second=tmp[i][j].second;
      }
    }
  }

  set<pii> s;

  //cout << gcd(1710,729) << endl;
  pii x=make_pair(1710,729); simplify(x);
  //cout << x.first << " " << x.second<< endl;
  for( int i=0; i<h; i++) {
    for( int j=0; j<w; j++) {
      //cout << arr[i][j].first<<"/"<<arr[i][j].second << " " ;
      //if(arr[i][j].first==0 || (arr[i][j].first==1 && arr[i][j].second==1)) continue;
	s.insert(arr[i][j]);
    }//cout << endl;
  }
  cout << s.size() << endl;
  return 0;
}
