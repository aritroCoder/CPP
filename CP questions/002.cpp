#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        //conv to lwrcase
        if ((s[i]>=65)&&(s[i]<=90))
        {
            s[i]= tolower(s[i]);
        }
        
    }
    for (int i = 0; i < s.size(); i++)
    {
        //erase vowels
        if ((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
        {
            s.erase(s.begin() + i);
        }
        else{
            s.insert(i, 1, '.');
        }
    }
    cout<<s;
    return 0;
}