#include<iostream>
#define int long long
using namespace std;

int t, n, m, k;
const int mod = 1000000007;

#undef int
int main(void) {
#define int long long
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        int fm, fn, sm, sn, ans1, ans2;
        fm = sm = m;
        fn = sn = n;
        ans1= ans2=1;
        bool flag = false;

        for(int i=0; i<k; i++) {
            if(i%2 == 0) {
                if(fn<1) {
                    flag = true;
                    break;
                }
                ans1 = (ans1*fn) % mod;
                fn--;
            } else {
                if(fm < 1) {
                    flag = true;
                    break;
                }
                ans1 = (ans1*fm) %mod;
                fm--;
            }
        }
        if(flag) {
            ans1 = 0;
        }
        flag = false;
        fm = m;
        fn = n;
        for(int i=0; i<k; i++) {
            if(i%2 == 1) {
                if(fn<1) {
                    flag = true;
                    break;
                }
                ans2 = (ans2*fn) % mod;
                fn--;
            } else {
                if(fm < 1) {
                    flag = true;
                    break;
                }
                ans2 = (ans2*fm) %mod;
                fm--;
            }
        }
        if(flag) ans2=0;

        int tot = (ans1+ans2)%mod;

        cout << tot << endl;

    }

    return 0;
}
