#include<iostream>
#include<queue>
#include<unordered_set>
#include<cstring>
using namespace std;
int f[51][51];
int fc[51];
int dis[51];
bool vis[51];
void addEdges(){
	f[2][6] = true;
	  f[6][2] = true;
	    f[1][6] = true;
		  f[6][1] = true;
		    f[6][7] = true;
			  f[7][6] = true;
			    f[3][6] = true;
				  f[6][3] = true;
				    f[4][6] = true;
					  f[6][4] = true;
					    f[5][6] = true;
						  f[6][5] = true;
						    f[7][8] = true;
							  f[8][7] = true;
							    f[3][4] = true;
								  f[4][3] = true;
								    f[4][5] = true;
									  f[5][4] = true;
									    f[3][5] = true;
										  f[5][3] = true;
										    f[8][9] = true;
											  f[9][8] = true;
											    f[3][15] = true;
												  f[15][3] = true;
												    f[9][12] = true;
													  f[12][9] = true;
													    f[9][10] = true;
														  f[10][9] = true;
														    f[10][11] = true;
															  f[11][10] = true;
															    f[11][12] = true;
																  f[12][11] = true;
																    f[13][15] = true;
																	  f[15][13] = true;
																	    f[12][13] = true;
																		  f[13][12] = true;
																		    f[13][14] = true;
																			  f[14][13] = true;
																			    f[16][18] = true;
																				  f[18][16] = true;
																				    f[16][17] = true;
																					  f[17][16] = true;
																					    f[17][18] = true;
																						  f[18][17] = true;
}
int main(){
	addEdges();
	unordered_set<int> ss;
	char instr;
	while(cin>>instr){
		if (instr == 'q') break;
		if (instr =='i'){
		int x,y; cin>> x >>y;
				f[x][y] = 1;
				f[y][x] = 1;
			continue;
		}
		if (instr == 'd'){
		int x,y; cin>> x >>y;
				f[x][y] = 0;
				f[y][x] = 0;
			continue;
		}
		if (instr == 'n'){
			int x; cin >>x;
			int res = 0;
			for(int i = 0; i < 50; i++){
				if (f[x][i]) res ++;
			}
		 	cout << res;
		}
		if (instr == 'f'){
			int x; cin>>x;
			ss.clear();
			for(int i =1;i < 50; i++) {
				if (f[i][x]){
					for(int j = 1; j < 50; j++){
						if (f[i][j]) {//cout << j<< " ";
						ss.insert(j);}
					}
				}
			}
			for(int i = 1;i < 50; i++){
				if (i !=x && f[i][x]){
					ss.erase(i);
				}
			}
			ss.erase(x);
			cout << ss.size();
		}
		if (instr == 's'){
			int x,y; cin>>x >>y;
			memset(dis, 0, sizeof dis);
			memset(vis, 0, sizeof vis);
			queue<int> q;
			q.push(x);
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int i =0; i< 50; i++){
					if (f[cur][i] && !vis[i]){
						vis[i] = true;
						dis[i] = dis[cur] + 1;
						q.push(i);
						if (i == y) break;
					}
				}
			
			}
			if (dis[y] == 0) cout <<"Not connected";
			else cout <<dis[y];
		}
		cout << "\n";

	}
}
