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
    
    while(t--)
    {
       int n, min_wt = 0, min_permutation;
       cin >> n;
       //DEBUG: 
    //    cout << "result: "<< endl;
       int permutation[n];
       for (int i = 0; i < n; i++)
       {
            permutation[i] = i+1;
       }

       int first_in_sequence = 0;
       for (int j = 0; j < n; j++)
        {
            first_in_sequence += permutation[j]*pow(10, n-j-1);
        }
        int first_weight = 0;
        for (int i = 1; i <= n; i++){
            if(first_in_sequence % i == 0) first_weight++;
        }
        min_wt = first_weight;
        min_permutation = first_in_sequence;

       do
       {
            int current_number = 0;
            for (int j = 0; j < n; j++)
            {
                current_number += permutation[j]*pow(10, n-j-1);
            }
            // DEBUG: 
            // cout << current_number << endl;
            int temp_wt = 0;
            for (int i = 1; i <= n; i++){
                if(current_number % i == 0) temp_wt++;
            }
            //DEBUG:
            // cout<<temp_wt << endl;
            if(min_wt > temp_wt){
                min_permutation = current_number;
                min_wt = temp_wt;
            }
            // DEBUG:
            // cout<<min_permutation << endl;
       } while (next_permutation(permutation, permutation+n));
       
    //    cout << to_string(min_permutation)<< endl;
        string result = to_string(min_permutation);
        for (int i = 0; i <= n-1; i++)
        {
            cout << result[i] << " ";
        }
        cout<<endl;
       
    }
    return 0;
}

// complexity: O(t*(n+n+n+2^n(n+n)+n))