#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        int n, finish = 0;
        cin >> n;
        int sleep_hr, sleep_min, sleep_time;
        cin >> sleep_hr >> sleep_min;
        vector<int> alarms; // will store time of alarm after converting to mins
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == sleep_hr && b == sleep_min)
            {
                cout << "0 0" << endl;
                finish = 1;
            }
            alarms.push_back(a * 60 + b);
        }
        if (finish)
            continue;
        sleep_time = sleep_hr * 60 + sleep_min;
        alarms.push_back(sleep_time);
        sort(alarms.begin(), alarms.end());
        for (auto it : alarms)
        {
            auto newIt = next(it, 1);
            if(it == sleep_time && newIt!=alarms.end())
                cout<< next(it, 1)/60 << " "<< next(it, 1)%60 << endl;
            else
                cout<< alarms.begin()/60 << " "<< alarms.begin()%60 << endl;
        }
    }
    return 0;
}