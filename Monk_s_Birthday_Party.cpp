// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

 
// Map to store the characters with their order
// in the new alphabetical order
unordered_map<char, int> h;
 
// Function that returns true if x < y
// according to the new alphabetical order
bool compare(string x, string y)
{
    for (int i = 0; i < min(x.size(), y.size()); i++) {
        if (h[x[i]] == h[y[i]])
            continue;
        return h[x[i]] < h[y[i]];
    }
    return x.size() < y.size();
}
 
// Driver code
int main()
{
    fastio;
    string str = "abcdefghijklmnopqrstuvwxyz";
    // vector<string> v{ "geeksforgeeks", "is", "the",
    //                   "best", "place", "for", "learning" };
    int t;
    cin >> t;
    
    while(t--)
    {
        vector<string> v;
        // Store the order for each character
        // in the new alphabetical sequence
        h.clear();
        int n;
        string temp;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < str.size(); i++)
            h[str[i]] = i;   
    
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size()-1; i++)
        {
            if (v[i] == v[i+1])
            {
                v.erase(v.begin()+i+1);
                i--;
            }
            
        }
        
        // Print the strings after sorting
        for (auto x : v)
            cout << x << "\n";
        
    }
    return 0;
}