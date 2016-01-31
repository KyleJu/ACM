#include<iostream>
#include<utility>
#include<unordered_set>
using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

void gen(int n) {
    unordered_set<pair<int, int>, pair_hash> s;
    while ((int)s.size() < n) {
        s.insert(pair<int, int>(rand() % 20000 - 10000, rand() % 20000 - 10000));
    }
    cout << s.size() << "\n";
    for (pair<int, int> p : s) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N = 100;
    cout << N << "\n";
    for (int i = 0; i < N; ++i) {
        gen(10000);
    }
    
    return 0;
}
