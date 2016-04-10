#include<bits/stdtr1c++.h>
using namespace std;

int N, A[200005], FM[200005], R;


// take min sum
// from right to left, calculate the value it needs to start from this point
// if this point add min >0 you know yo can shift
int main () {
    // ifstream cin("positive.in");
    // ofstream cout("positive.out");
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    int sum = 0;
    for (int i = 0; i < N; ++i)
        FM[i] = i?min(FM[i-1], sum+=A[i]):sum+=A[0];
    
    R = (FM[N-1] > 0);
    sum = 0;
    int ms = numeric_limits<int>::max() - 1000000;
    cout << ms << " ms " << endl;
    for (int i = N-1; i > 0; --i) {
        sum += A[i];
        ms = min(A[i], ms + A[i]);
        if (ms > 0)
            R += (FM[i-1] + sum > 0);
        //cout << sum << " " << ms  << " "  << A[i]<< endl;
    }
    
    cout << R << endl;
    
    return 0;
}