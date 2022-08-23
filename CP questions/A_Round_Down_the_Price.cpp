#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int no_of_digits(long int n)
{
    int d = 0;
    while (n)
    {
        n /= 10;
        d++;
    }
    return d;
}

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        long int n, rnd = 1;
        cin >> n;
        for (; n >= rnd*10;)
            rnd *= 10;
        cout << n-rnd << endl;
    }
    return 0;
}