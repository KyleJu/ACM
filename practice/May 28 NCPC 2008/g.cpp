#include<iostream>
#include<cstring>
using namespace std;
const int N = 55;
int W,H;
char wall[N][N];
bool vis[N][N];
int xx[] = {1 ,-1, 0, 0};
int yy[] = {0,0,1,-1};
int res;
void dfs(int x,int y) {
    vis[x][y] = true;   
    if (wall[x][y] == 'G') res++;
    for (int i = 0; i<4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx <0 || ny < 0 || nx >=H || ny >=W) continue;
        if (wall[nx][ny] == 'T') return;
    }
    for (int i =0; i< 4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx <0 || ny < 0 || nx >=H || ny >=W) continue;
        if (vis[nx][ny]) continue;
        if (wall[nx][ny] == '.' || wall[nx][ny] =='G') dfs(nx,ny);
    }
}
 
int main() {
    cin >> W >>H;
    memset(vis, 0, sizeof vis);
    string tm;
    int x = -1;
    int y = -1;
    for(int i =0; i < H;i++){
        cin>>tm;
        for(int j = 0; j < W; j++) {
            wall[i][j] = tm[j]; 
            if (tm[j] == 'P') {
                x = i; y = j;
            }
        }
    }
     dfs(x,y);
    cout << res << endl;
     
 
}