#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int w,h,d;
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
vector<string> mm;
bool vis[505][505];
int main(){
	int ts; cin >>ts;
	while(ts--) {
		cin >> h >> w >> d;	
		string s;
		pi start;
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < h; i++) {
			cin>>s;
			mm.push_back(s);
			for(int j = 0; j < w; j++) {
				if ( s[j] == 'S') {
					start = make_pair(i,j);	
				}
			}
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push(make_pair(0,start));	
		bool found = false;
		while(!pq.empty()) {

			pii cur = pq.top(); pq.pop();
			cout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
			pi co = cur.second;
			if (vis[co.first][co.second]) continue;
			vis[co.first][co.second] = true;
			//cout <<"etd" << endl;
			for(int i = 0; i < 4; i++ ){
			 	int xx = x[i];
				int yy = y[i];
				int nx = xx + co.first;
				int ny = yy + co.second;
				if ( nx <0 || nx >=h || ny < 0 || ny >=w) {
					cout << cur.first + 1 << endl;
					found = true;
					break;
				}
				//cout << "edfd " << endl;
				if ( vis[nx][ny]) continue;
				if ( mm[nx][ny] == '#') continue;
				if (mm[nx][ny] == '.') pq.push(make_pair(cur.first + 1, make_pair(nx,ny)));
				if (mm[nx][ny] == '@') pq.push(make_pair(cur.first + d +1, make_pair(nx,ny)));
			 }
			 if (found) break;
		}

	}
}
