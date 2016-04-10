#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vi;
typedef pair<int, pi> pii;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
bool vis[(int)1e3 + 5][(int)1e3+5];
vi ports;
vector<string> maze;
int main(){
	int ts; cin >>ts;
	while(ts--){
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		maze.clear();
		memset(vis, 0, sizeof vis);
		ports.clear();
		int w; cin>> w ;
		for(int i = 0; i < w; i++){
			string s; cin>>s;
			maze.push_back(s);
			//get a list of p and starting points;
			for(int j = 0;j < w; j++){
				
				if (s[j] == 'P') ports.push_back(make_pair(i,j));
				if (s[j] == 'S') pq.push(make_pair(0,make_pair(i,j)));	
			}
		}
		int res = -1;
		bool pUsed = false;
		bool found =false;
		while(!pq.empty()){
			pii cur = pq.top(); pq.pop();
			pi point = cur.second;
			//cout << cur.first << " " << point.first << " " << point.second<<endl;
			if (vis[point.first][point.second]) continue;
			vis[point.first][point.second] = true;
			for(int i =0; i <4;i++){
					int xx = point.first + x[i];
					int yy = point.second + y[i];
					if (xx>= w || xx<0) continue;
					if (yy >=w || yy <0) continue;
					if (maze[xx][yy] == 'X') continue;
					if (maze[xx][yy] == 'S') continue;
					//cout << maze[xx][yy] <<" " <<  xx<< " "  << yy << endl;
					if (maze[xx][yy] == 'E') {
					//cout << "here" <<endl; 
						found = true;
						res = cur.first+ 1;
						break;
					}
					if(maze[xx][yy] == '.')
						pq.push(make_pair(cur.first + 1, make_pair(xx,yy)));
					if (maze[xx][yy] =='_')
						pq.push(make_pair(cur.first +2, make_pair(xx,yy)));
					if (maze[xx][yy] =='P'){
						if (!pUsed) {
							pUsed = true;
							for(auto po: ports){
								pq.push(make_pair(cur.first,po));
							}
						}
					}
			}
			//	cout << "here2" <<endl;
			if (found) break;
		}
		cout << res << endl;

	}
}
