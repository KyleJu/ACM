#include<bits/stdtr1c++.h>
using namespace std;

vector<int> board;
vector<int> moves;

int main() {
    int t; cin >> t;
    while (t--) {
        bool flag = false;
        int n, m;
        cin >> n >> m;
        board.clear();
        moves.clear();
        for (int i=0; i<=n; i++) {
            int x; cin >> x;
            board.push_back(x);
        }
        string s; cin >> s;
        for (int i=0; i<m; i++) {
            moves.push_back(s[i]-'0');
        }
        int current = 0;
        for( int i=0; i<moves.size(); i++) {
            int x = moves[i];
            if (current + x > n)
                continue;
            current += x;
            current += board[current];
            if(current == n) {
                flag = true;
                break;
            }
            //cout << current << " ";
        }
        //cout << endl;
        if(flag) {
            cout << "win" << endl;
        } else {
            cout << "game in progress" << endl;
        }
    }
}
