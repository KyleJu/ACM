#include<bits/stdtr1c++.h>
 
using namespace std;
bool vis [205][205];
int main() {
    int m,n; cin >> m >> n;
    vector<string> arr;
    string tm;
    for(int i =  0; i < m; i++) {
        cin >> tm;
        arr.push_back(tm);    
    }   
    int res = 0;
    int i = 0;
    int j = 0;
     
    while(arr[i][j] != 'T'){
        if(vis[i][j]) { cout << "Lost" << endl; return 0;}
        vis[i][j] = true;
        if(arr[i][j] == 'E') j++;
        else if (arr[i][j] == 'N') i--;
        else if (arr[i][j] == 'S') i++;
        else if ( arr[i][j] == 'W') j--;
        if( i <0 || i >=m || j <0  || j >= n) { cout <<"Out" << endl; return 0;}
        res++;
    }   
    cout << res << endl;
}
