#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int arr[4]; //zero initialised global array

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        fill(arr, arr+4, 0); //zero initialised global array
        string s;
        cin >> s;
        int min;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'r')
            {
                arr[0]++;
            }
            else if (s[i] == 'u')
            {
                arr[1]++;
            }
            else if (s[i] == 'b')
            {
                arr[2]++;
            }
            else if (s[i] == 'y')
            {
                arr[3]++;
            }
        }
        min =  arr[1];
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        cout << min << endl;
    }
    return 0;
}