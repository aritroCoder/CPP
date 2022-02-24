#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    long long time = 0, last= 1;
    for (int i = 0; i < m; i++)
    {
        if(a[i]-last >= 0){
            time += a[i]-last;
        }
        else{
            time += n + a[i]-last;
        }
        last = a[i];
    }
    cout <<time<<endl;
    return 0;
}