#include<bits/stdtr1c++.h>
using namespace std;

unordered_set<string> dict;
int n, l, m;

int main() {
    int t; cin >> t;
    while (t--) {
        dict.clear();
        cin >> n >> l >> m;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            dict.insert(s);
        }

        for (int i=0; i<m; i++) {
            string q; cin >> q;
            if (dict.find(q) != dict.end()) {
                cout << "correct spelling" << endl;
                continue;
            }
            string tmp = q;
            int sug = 0;
            for (int i=0; i<q.size(); i++) {
                tmp = q;
                for (int j=0; j<26; j++) {
                    char ch = (char)('a'+j);
                    tmp[i]=ch;
                    if (dict.find(tmp) != dict.end()) {
                        sug++;
                    }
                }
            }
            cout << sug << " suggestion(s)" << endl;
        }
    }
} 
