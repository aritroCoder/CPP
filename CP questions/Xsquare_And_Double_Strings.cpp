#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int hsh[(int)'z' + 1];
int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        //reset the hash arrays
        fill(hsh, hsh + (int)'z' + 1, 0);
        string s;
        cin >> s;
        for (int i = 'a'; i < s.size(); i++)
        {
            hsh[(int)s[i]]++; //creating hash array
        }
        int odd=0, even=0;
        for (int i = 'a'; i <= 'z'; i++)
        {
            if(hsh[i]%2 == 0 && hsh[i] != 0){even++;}
            if(hsh[i]%2 == 1){odd++;}
        }
        if(even==0){
            cout << "NO" <<endl;
        }
        else{
            cout << "YES" <<endl;
        }
        
    }
    return 0;
}