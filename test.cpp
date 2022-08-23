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
    int l = s.length();
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='{'||  s[i]=='}' || s[i]==','){
            s.erase(i, 1);
            i--;
            cout<<endl<<"debug output: "<<s<<endl;
        }
    }
    return 0;
}