/// always index + 1
// forgot to clear max in the beginning
//bucs[index/size]
//>=0
// index + 1- size
#include<bits/stdtr1c++.h>
using namespace std;
vector<int> arr;
vector<int> bucs;
int buckets;
int size;
int qry(int n){
    int res = -1;
    int index = n-1;
    //cout << "index is" << n << "\n";
    while((index+1)%size !=0 && index >=0){
        if(arr[index] >= arr[n]){
            res = index;
            return res;
        }
        index--;
    }

    while(index +1 - size >=0){
        if(bucs[index/size] >= arr[n]){
            //cout << n << " " << index/size << " " << bucs[index/size] << "\n";
            break;
        } 
        if(index < size) return -1;
        index = index -size;
    }
    int temp = index;
    while(index == temp || ((index+1)%size != 0 && index >=0)){
        //cerr << "third loop" <<  index << " " << arr[index] << "\n";
        if (arr[index] >= arr[n]){
            res = index;
            return res;
         }
        index--;
    }
    return res;
}

int main(){
    int ts; cin >>ts;
    while(ts--){
        bucs.clear();
        arr.clear();
        int n; cin >>n;
        int ma = 0;
        buckets = ceil(sqrt(n));
        size = sqrt(n);
        for(int i = 0; i < n;i++){
            int tm; cin >>tm;
            if(i !=0 && (i%size ==0)){
                bucs.push_back(ma);
                ma = 0;
            }
            ma = max(ma, tm);
            arr.push_back(tm);
        }
        bucs.push_back(ma);
        //debug 
        //
        /*
        for(int i =0; i <bucs.size(); i++){
            cout << bucs[i] << " ";
        }
        cout << "\n";

        cout << " ******* " << "\n";
        */
        for(int i = 0; i < n; i++){
            int res = qry(i);
            if(res ==-1) cout << "X";
            else cout << res + 1;
            if (i != n-1) cout << " ";
        }
        cout << "\n";

    }
}
