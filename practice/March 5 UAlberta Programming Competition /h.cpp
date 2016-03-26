#include<iostream>
#include<string>
#include<iomanip>
#define int long long

//
//if ((N * 1e8) % D == 0) return N / D
//else return ERROR

using namespace std;

int N,D,n,d;
string s;
#undef int
int main(void) {
#define int long long
    int T; cin >> T;
    while(T--) {
        cin >> N >> s >> D;
        d = D;
        n = N%d;
        if(n<0) n *= -1;
        if(d<0) d *= -1;
        // cout << n << "/" << d << endl;

        
        int count = 0;
        while(count < 8 && n%d != 0) {
            n *= 10;
            count++;
        }
        // cout << n << " " << d << endl;
        long double n2 = N, d2 = D;
    

        // cout << fixed << setprecision(8) << n2/d2 << endl;
        if(n%d == 0 || N%D == 0) {
            cout << fixed << setprecision(8) << n2/d2 << endl;
        } else {
            cout << "ERROR" << endl;
        }
    }
    // cout << (342*(long long)100000000)%6400 << endl;
    return 0;
}
