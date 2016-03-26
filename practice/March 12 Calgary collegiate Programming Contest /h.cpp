#include<bits/stdtr1c++.h>
using namespace std;


vector<int> v;

int main (){
    int ts; cin>>ts;

    while(ts--){
        v.clear();
        int n; cin>>n;
        n = 2*n;
        for(int i = 0; i < n;i++){
            int x; cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        for(int i 
        int ma = v[n-1];
        int count = 1;
        int index = n-2;
        while(index>=0 && (v[index] == ma)){
            //cout << "index: " << index << ", value: " << v[index] << endl;
            count++;
            index--;
        }
        //cout << count << "count"  << "\n";
        if(count >= n/2) {
            cout << v[n-1] - v[0] << endl;
            continue;
        }
        cout << v[n-1] - v[n/2-count] << endl;

    }
}
