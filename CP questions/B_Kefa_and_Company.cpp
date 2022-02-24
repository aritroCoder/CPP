#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, d;// n = number of friends, d= maximum difference of money allowed
    vector<pair<int, int>> v; //vector of pair for storing money of friends and friendship value
    //taking inputs
    while(n--){
        int m, s;
        cin >> m >> s;
        v.push_back(make_pair(m, s));
    }
    //sort by second element in non increasing order
    sort(v.begin(), v.end(), [] (const auto &x, const auto &y) { return x.second > y.second; });
    int res = 0;  //variable for storing maximum possible friendship value
    int maxM = max_element(v.begin(), v.end())->first; //getting maximum value of money
    //if difference between maximum money and money of friends is less than or equal to d, add friendship value to res
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if(maxM-(i->first) > d){
            res+=0;
        }
        else{
            res+= i->second;
        }
    }
    cout << res << endl;
    return 0;
}