#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin >> N >> K;
        vector<int> v;
        for(int i=0; i<N; i++){
            int p;
            cin >> p;
            v.push_back(p);
        }
        for(int i=0; i<v.size()-K+1; i++){
            cout << *max_element(v.begin()+i, v.begin()+i+K) << " ";
        }
        cout<<endl;
    }
    return 0;
}
