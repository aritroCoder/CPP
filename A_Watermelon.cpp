#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int a;
    cin>>a;
    //hardcode initial conditions
    if(a==0){
        cout<<"NO";
        return 0;
    }else if(a==1){
        cout<<"NO";
        return 0;
    }else if(a==2){
        cout<<"NO";
        return 0;
    }
    if(a%2 == 0) cout<<"YES";
    else cout<<"NO";
    return 0;
}