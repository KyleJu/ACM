#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// always clear the tree when you start a new bucket
// since inside of a bucket it sorts based on end points
// to avoid duplicates -> use pair<int, int> with a counter
// when casting, add brackets(int )(l/sqrt(n))!!!
typedef tree<
pair<int,int>,
null_type,
greater<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
i_order;

int n;
i_order tr;

struct q{
    int a,b,c,i;
    bool operator<(const q& o)const{
        if((int)(a/sqrt(n)) == (int)(o.a/sqrt(n))) return b<o.b;
        return (int)(a/sqrt(n)) < (int)(o.a/sqrt(n));
    }
};

typedef vector<int> vi;
typedef pair<int,int> pii;
int couter[100005];
vi arr;
vector<q> qs;
pair<int,int> res[10001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        tr.clear();
        arr.clear();
        qs.clear();
        memset(couter, 0, sizeof couter);
        memset(res, 0, sizeof res);
        cin>>n;
        for (int i = 0; i <n; i++){
            int tem; cin>> tem;
            arr.push_back(tem);
        }
        int qn; cin>>qn;
        for (int i = 0; i <qn;i++){
            q te; cin>>te.a>>te.b>>te.c;
            te.i = i;
            qs.push_back(te);
        } 
        //ers
        sort(qs.begin(), qs.end());
        
        /// debug 
        
        q pre;
        for (int i = 0 ; i< qn; i++) {
           // cout << qs[i].a << " " << qs[i].b << " "  <<qs[i].c << "queries \n"; 
            int l = qs[i].a;
            int r = qs[i].b;
            if( i ==0 || ((int)(l/sqrt(n)) != (int)(pre.a/sqrt(n)))){
                //cout << "here"<< endl;
                tr.clear();
                while(l<=r){
                    //cout << arr[l] << " " << couter[arr[l]] << "\n";
                    tr.insert(make_pair(arr[l], couter[arr[l]]++));
                    l++;
                }
            
                
            } else {
                int pr = pre.b;
                if (pr < r) {
                    while(++pr <=r){
                        //cout << arr[pr] << " " << couter[arr[pr]] << "\n";
                
                        tr.insert(make_pair(arr[pr], couter[arr[pr]]++));
                    }
                } else if (pr >r) {
                    while(pr >r ){
                        //cout << tr.size() << "size\n" ;
                        tr.erase(make_pair(arr[pr],--couter[arr[pr]]));
                        //cout << tr.size() << "size\n";
                        pr--;
                    }
                }
                int pl = pre.a;
                if (pl< l) {
                    while(pl<l){
                        tr.erase(make_pair(arr[pl],--couter[arr[pl]]));
                        pl++;
                    }
                } else if(pl >l){
                    while(l <pl){
                        tr.insert(make_pair(arr[l], couter[arr[l]]++));
                        l++;
                    }
                }
            }
            pre = qs[i];
            res[qs[i].i] = *tr.find_by_order(qs[i].c -1);
        }
        for (int i = 0; i < qn; i++){
            cout << res[i].first << "\n";
        }
    }
}
