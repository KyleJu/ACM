//#include<bits/stdtr1c++.h>
#include<iostream>
#include<algorithm>
using namespace std;
// when you do inclusive,exlucsive you need to make sure that the starting numner of exclusive is not part of the solution
// otherwise it will never get chosen
typedef long long ll;
#define int long long
const int N = 50005;
ll arr[N];
ll pre[N];
int b,n;
int mw;
bool pack(ll g) {
    ll cur = 0;
    ll used = 0;
    ll t = 0;
    while (cur != n) {
        if (used==b) return false;
        t += arr[cur];
        if (t > g) {
            //cout << "asd: " << used << " " << cur << endl;
            used++;
            t = 0;
            cur--;
        }
        cur++;
    }
    return used <= b;
    //int temp = b;
    //ll p = 0;
    //while (temp--) {
    //    auto it = upper_bound(pre, pre+n, p+g);
    //    if (it == pre + n)
    //        return true;
    //    it--;
    //    p=*it;
    //}
    //return false; 
}
#undef int
int main(){
#define int long long
    int ts; cin >>ts;
    while(ts--){
        memset(arr,0,sizeof arr);
        memset(pre,0,sizeof pre);
        mw = -1;
        cin>>n;
        cin >>b;
        for (int i=0; i<n; i++) {
           cin >> arr[i]; 
           mw = max(mw,arr[i]);
       }
        pre[0] = arr[0];
       for (int i=1; i<n; i++) pre[i] = pre[i-1]+arr[i]; 
    
        int lo = mw - 1 ; int hi = pre[n-1] + 1;

        while(lo + 1 < hi) {
            int mid = (lo + hi)/2;
            if (pack(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        // while (lo<hi) {
        //     int mid = lo + (hi-lo)/2;;
        //     //cout << mid << " " << pack(mid) << endl;
        //     if (pack(mid)) {
        //         hi = mid;
        //     } else {
        //         lo = mid+1;
        //     }

        // }
        cout <<hi << "\n";
    }
}
