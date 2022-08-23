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
    int h=0, e=0, l1=0, l2=0, o=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(h==0){
            if(s[i]=='h') h=1;
        }else if(e==0){
            if(s[i]=='e') e=1;
        }else if(l1==0){
            if(s[i]=='l') l1=1;
        }else if(l2==0){
            if(s[i]=='l') l2=1;
        }else if(o==0){
            if(s[i]=='o') o=1;
        }
    }
    if(h*e*l1*l2*o == 1) cout<<"YES"<< endl;
    else cout<<"NO"<<endl;
    
    return 0;
}