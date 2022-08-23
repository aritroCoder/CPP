#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
       long double a, b, c, d;
       cin>>a>>b>>c>>d;
       if(a/b == c/d) cout<<0<<endl;
       else if(a/b == 0 || c/d == 0) cout<<1<<endl;
       else{
        long double e, f;
        e = a/b;
        f = c/d;
        if(e/f == floor(e/f) || f/e == floor(f/e)) cout<<1<<endl;
        else cout<<2<<endl;//if only one int can be mul in num or we have to multiply at both num and denominator
       }
    }
    return 0;
}