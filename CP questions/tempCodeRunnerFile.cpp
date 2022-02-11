#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, ans=0;
    cin >> n ;
    long long arr[n+1], pf[n+1]; 
    pf[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pf[i]=pf[i-1]+arr[i]; //computing the prefix sum
    }
    //sort the prefix sum
    sort(pf, pf+n+1);
    for (int i = 1; i < n; i++)
    {
        if(pf[i]==pf[i+1]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}