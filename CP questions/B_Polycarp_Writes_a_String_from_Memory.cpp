#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t, hsh[123];
    cin >> t;

    while (t--)
    {
        int unique_letters=0;
        for (int i = 0; i < 123; i++)
        {
            hsh[i] = 0;
        }
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if(hsh[s[i]]==0){ 
                hsh[s[i]] = 1;
                unique_letters++;
                cout<<"\n"<<s[i]<<" detected "<< endl;
            }
        }
        // cout << ceil(unique_letters/3.00) << endl;
        
    }
    return 0;
}