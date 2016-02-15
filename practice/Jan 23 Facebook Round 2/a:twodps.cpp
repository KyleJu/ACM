#include<bits/stdtr1c++.h>
using namespace std;

int T, N;
string A, B;
int F[100005][2], K[100005][2];

int dec(int i, char c = ' ') {
    if (i < 0 || i >= N) return 0;
    return A[i] != (c == ' ' ? B[i] : c);
}

int dpf(int a, int b) {
    if(a >= N) return 0;
    if(F[a][b] != -1) return F[a][b];
    if(!b && A[a] == B[a]) return F[a][b] = dpf(a+1, 0);
    if(!b && A[a] != B[a]) return F[a][b] = 1 + dpf(a+1, 1);
    if(b && B[a] == B[a-1]) return F[a][b] = dpf(a+1, 1);
    if(b && B[a] != B[a-1]) return F[a][b] = 1 + dpf(a+1, 1);
    return -1;
}

int dpb(int a, int b) {
    if(a < 0) return 0;
    if(K[a][b] != -1) return K[a][b];
    if(!b && A[a] == B[a]) return K[a][b] = dpb(a-1, 0);
    if(!b && A[a] != B[a]) return K[a][b] = 1 + dpb(a-1, 1);
    if(b && B[a] == B[a+1]) return K[a][b] = dpb(a-1, 1);
    if(b && B[a] != B[a+1]) return K[a][b] = 1 + dpb(a-1, 1);
    return -1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> A >> B;
        
        memset(F, -1, sizeof F);
        memset(K, -1, sizeof K);
        //cout << A << endl << B << endl;
        
        int res = numeric_limits<int>::max();
        
        for (int i = 0; i <= N; ++i) {
            res = min(res, max(dpf(i, 0), dpb(i-1, 0)));
            //cout << i << " " << dpf(i, 0) << " " << dpb(i-1, 0) << endl;
        }
        
        cout << "Case #" << t << ": " << res << endl;
    }
    
    return 0;
}
