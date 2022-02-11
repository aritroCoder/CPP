#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

const int P= 10e6 + 9;
int hsh[P];
int main()
{
    fastio;
    int n, k, flg=0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hsh[a[i]]++;
    }
    for (int i = 0; i < P; i++){
        if(k-i>=0 && hsh[k-i]>0 && hsh[i]>0 && 2*i!=k){
            cout << "YES"<< endl;
            // cout << i<< " "<< k-i << endl;
            flg=1;
            break;
        }
        else if(k-i>=0 && hsh[k-i]>1 &&  k/2==i){
            cout<< "YES"<< endl;
            flg=1;
            break;
        }
    }
    if(flg==0){
        cout << "NO" << endl;
    }
    
    return 0;
}