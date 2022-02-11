#include <bits/stdc++.h>
using namespace std;
int main()
{
    //int i=0;
    string s = "aBAcab";
    cout << "input the string" << endl;
    for (int m = 0; m < (s.size()); m += 2)
    {
        s.insert(m, "RT");
            // cout<<s<<endl;
    }
    cout << " the string is" << s;
    return 0;
}