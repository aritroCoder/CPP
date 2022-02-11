#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
int hsh1[(int)'z' + 1], hsh2[(int)'z' + 1];
using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        //reset the hash arrays
        fill(hsh1, hsh1 + (int)'z' + 1, 0);
        fill(hsh2, hsh2 + (int)'z' + 1, 0);
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
        //compare the hash arrays
        int flg=0;
        for (int i = (int)'a'; i < (int)'z'+1; i++)
        {
            if((hsh1[i]>0) && (hsh2[i] < hsh1[i])){
                flg++; 
                break;
            }
        }
        if(flg==0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        //show the hash arrays
        cout << "hsh1"<< endl;
        for (int i = (int)'a'; i < (int)'z'+1; i++)
        {
            cout << hsh1[i] <<" ";
        }
        cout<<endl;
        cout << "hsh2"<< endl;
        for (int i = (int)'a'; i < (int)'z'+1; i++)
        {
            cout << hsh2[i] <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}