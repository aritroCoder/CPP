#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int main()
{
    fastio;
    int turns, choice, c = 0;
    cin >> turns >> choice;
    int pos_to_remove[choice];
    for (int i = 0; i < choice; i++)
    {
        cin >> pos_to_remove[i];
    }
    string s = "";
    int turndesc[turns];
    for (int i = 0; i < turns; i++)
    {
        cin >> turndesc[i];
    }
    //reading turns
    for (int i = 0; i < turns; i++)
    {
        c=0;
        if (turndesc[i] == 0)
        {
            s.push_back('0');
            cout << "after turn" << i << ":" << s << endl;
        }
        if (turndesc[i] == 1)
        {
            s.push_back('1');
            cout << "after turn" << i << ":" << s << endl;
        }
        if (turndesc[i] == -1)
        {
            if (pos_to_remove[0] > s.size())
            {
                cout << "after turn " << i << ":" << s << endl;
                continue;
            }
            while (pos_to_remove[c] <= s.size())
            {
                s[pos_to_remove[c]-1 ] = '*';
                cout<<"removing pos "<<pos_to_remove[c]<<endl;
                cout<<s << endl;
                c++;
            }
            cout<<"done removing positions"<<endl;
            //remove space
            int len = s.size();
            for (int i = 0; i < len; i++)
            {
                if (s[i] == '*')
                {
                    for (int j = i; j < len; j++)
                        s[j] = s[j + 1];
                    len--;
                }
            }
            cout << "after turn" << i << ":" << s << endl;
        }
    }
    if (s == " ")
        cout << "Poor stack!" << endl;
    else
        cout << s << endl;
    return 0;
}