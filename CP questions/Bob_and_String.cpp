#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int hsh1[(int)'z'+1], hsh2[(int)'z'+1];

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        fill(hsh1, hsh1+(int)'z'+1, 0);
        fill(hsh2, hsh2+(int)'z'+1, 0);
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++)
        {
            hsh1[(int)a[i]]++; //creating hash array
        }
        for (int i = 0; i < b.size(); i++)
        {
            hsh2[(int)b[i]]++; //creating hash array
        }
        int op=0;
        for (int i = 0; i < (int)'z'+1; i++)
        {
            op+=abs(hsh2[i]-hsh1[i]);
            // cout << "hash 1 " << hsh1[i] <<endl;
            // cout << "hash 2 " << hsh2[i] <<endl;
            // cout << "op " << op << endl;
        }
        cout << op << endl;
        
    }
    return 0;
}