#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

long long fn(int n)
{
    long long f=0;
    for (int i = 1; i <= n; i++)
    {
        f += n % i;
    }
    return f;
}

int main()
{
    fastio;
    long long L, R, sum=0;
    cin >> L >> R;
    for (int i = L; i <= R; i++)
    {
        if(fn(i)==fn(i-1)) {sum+=i;}
    }
    cout << sum << endl;
    return 0;
}