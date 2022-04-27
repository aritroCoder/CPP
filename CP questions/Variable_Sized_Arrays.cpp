#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<vector<int>> v;
    int n, q, k;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin>>k;
        vector<int> p;
        p.clear();
        for(int j=0; j<k; j++){
            int tmp;
            cin>>tmp;
            p.push_back(tmp);
        }
        v.push_back(p);
    }
    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        cout << v[x][y] <<endl;
    }
    return 0;
}
