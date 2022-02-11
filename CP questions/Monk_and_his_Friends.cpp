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
        vector<long long> currCandies;
        long long temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            currCandies.push_back(temp);
        }
        for (int i = 0; i < M; i++)
        {
        sort(currCandies.begin(), currCandies.end());
            cin >> temp;
            bool it = binary_search(currCandies.begin(), currCandies.end(), temp);
            if (it){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            currCandies.push_back(temp);
            
        }
    }
    return 0;
}