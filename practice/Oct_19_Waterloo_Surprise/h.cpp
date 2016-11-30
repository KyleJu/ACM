#include<bits/stdtr1c++.h>
 
const int MAX = 100005;
 
using namespace std;
class UnionFind
{
  public:
  
    int id[MAX], sz[MAX];
    UnionFind(int n)   //class constructor
    {
        for (int i = 0; i < n; ++i)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
      
    int root(int i)
    {
        while(i != id[i])
        {
            id[i] = id[id[i]];  //path Compression
            i = id[i];
        }
        return i;
    }
    int find(int p, int q)
    {
        return root(p)==root(q);
    }
    void unite(int p, int q)
    {
        int i = root(p);
        int j = root(q);
 
        if (i == j) return;
  
        if(sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};
 
int main() {
    int t; cin >> t;
    while (t--) {  
        int cnt = 0;
        map<string, int> mapper;
        int f; cin >> f;
        UnionFind uf(MAX);
        for (int i = 0; i < f; i++) {
            string x, y; cin >> x >> y;
            if (mapper.find(x) == mapper.end())
                mapper[x] = ++cnt;
            if (mapper.find(y) == mapper.end())
                mapper[y] = ++cnt;
            uf.unite(mapper[x], mapper[y]);
            cout << uf.sz[uf.root(mapper[x])] << endl;
        }
    }
}
