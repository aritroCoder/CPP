#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    vector<int> X, Y;
    cin>>N;
    for(int i=0; i<N; i++){
        int k;
        cin >> k;
        X.push_back(k);
    }
    cin>>Q;
    for(int i=0; i<Q; i++){
        int k;
        cin>>k;
        Y.push_back(k);
    }
    for(int i=0; i<Q; i++){
        auto it=lower_bound(X.begin(), X.end(), Y[i]);
        if(i>0) cout<<" ";
        if(*it == Y[i]){
            cout<<"YES "<<it-X.begin()+1<<endl;
        }
        else cout<<"NO "<<it-X.begin()+1<<endl;
    }
    return 0;
}
