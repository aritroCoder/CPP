#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s1, s2;
    float a1=0, a2=0;
    cin>>s1>> s2;
//convert both strings to lower case
    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i]>=65 && s1[i]<=90) s1[i] = s1[i]+32;
        if(s2[i]>=65 && s2[i]<=90) s2[i] = s2[i]+32;
    }
    
    for (int i = 0; i < s1.size(); i++)
    {
        a1 += s1[i]*pow(10, -i);
        a2 += s2[i]*pow(10, -i);
    }
    
    if(a1>a2) cout<<"1"<<endl;
    else if(a1 == a2) cout<<"0"<<endl;
    else cout<<"-1"<<endl;
    return 0;
}