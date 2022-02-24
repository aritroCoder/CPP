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
       int l, f;
       cin >> l >> f;
       string s, rev;
       cin >> s;
       rev = s;
       reverse(rev.begin(), rev.end());
       if (rev == s)
       {
           cout << "1" << endl;
       }
       else
       {
           string temp, rev_temp;
           int res = 1;
           temp = s; rev_temp = rev;
           while(temp != rev_temp && f>0){
               res *= 2;
               temp = temp + rev_temp;
            //    rev_temp = reverse(temp.begin(), temp.end());
               rev_temp = temp;
               reverse(rev_temp.begin(), rev_temp.end());
               f--;
           }
           cout << res << endl;
       }
       
    }
    return 0;
}