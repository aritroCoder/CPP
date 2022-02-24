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
        // current students = N, new students = M
        int M, N;
        cin >> N >> M;
        // vector<long long> currCandies;
        set<long long> currCandies;
        long long temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            currCandies.insert(temp);
        }
        for (int i = 0; i < M; i++)
        {
        // sort(currCandies.begin(), currCandies.end());
            cin >> temp;
            // bool it = binary_search(currCandies.begin(), currCandies.end(), temp);
            auto it = currCandies.find(temp);
            if (it != currCandies.end()){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            currCandies.insert(temp);
            
        }
    }
    return 0;
}