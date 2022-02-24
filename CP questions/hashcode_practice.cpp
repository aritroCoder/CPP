#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

vector<vector<string>> client_likes;
vector<vector<string>> client_dislikes;
vector<string> disliked_components;
int t;

bool checksubset(vector<string> A, vector<string> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return includes(A.begin(), A.end(), B.begin(), B.end());
}

// int checkPizza(int client, int no_of_clients, vector<vector<string>> client_likes, vector<vector<string>> client_dislikes){
//         int pizzaSold = 0;
//     for (int i = 0; i < no_of_clients; i++)
//     {
//         if(checksubset(client_likes[client], client_likes[i])) pizzaSold++;
//     }
//     return pizzaSold;
// }

// algo 2.0 : create a giant vector with all the names of the unique liking ingredients, then test the code for all possible subsets of the vector, subset with highest customers win

void unique_elements(vector<string> &vec)
{

    //   map<string, int> m;

    //   for(auto p=vec.begin(); p!=vec.end(); ++p)
    //     m[*p]++;

    //   vec.clear();

    //   for(auto p=m.begin(); p!=m.end(); ++p)
    //     if (p->second == 1) vec.push_back(p->first);
    sort(vec.begin(), vec.end());

    auto iter = unique(vec.begin(), vec.end());

    vec.erase(iter, vec.end());
}

int check(vector<string> &v)
{
    int pizzasell = 0;
    for (int i = 0; i < t; i++)
    {
        if (checksubset(v, client_likes[i]) && (find_first_of(client_dislikes[i].begin(), client_dislikes[i].end(), v.begin(), v.end()) == client_dislikes[i].end()))
        {
            // checking if client_dislikes and v are disjoint or not
            pizzasell++;
        }
    }
    return pizzasell;
}

void algo2()
{
    vector<string> liked_components;
    for (auto g : client_likes)
    {
        for (auto h : g)
        {
            liked_components.push_back(h);
        }
    }
    cout << "created linear like vector" << endl;
    // for debug
    //  for(auto g: liked_components){
    //      cout<< g<< endl;
    //  }
    for (auto g : client_dislikes)
    {
        for (auto h : g)
        {
            disliked_components.push_back(h);
        }
    }
    cout << "created linear dislike vector" << endl;
    // remove duplicates entries from giant vector
    unique_elements(liked_components);
    unique_elements(disliked_components);
    cout << "Removed duplicate elements" << endl;
    // for debug
    //  cout <<"disliked Items:"<<endl;
    //  for(auto g: disliked_components){
    //      cout<< g<<endl;
    //  }
    int clientScore = 0, passcount = 0;
    int m = 0;
    vector<string> temp_vec;
    vector<string> result_vec;
    cout << "start creating subset and checking results" << endl;
    for (m = 0; m < liked_components.size(); m++)
    {
        for (int n = m; n < liked_components.size(); n++)
        {
            temp_vec.clear();
            for (int o = m; o <= n; o++)
            {
                temp_vec.push_back(liked_components[o]); // create all possible subset of the vector to test
            }
            if (check(temp_vec) > clientScore)
            {
                clientScore = check(temp_vec);
                result_vec = temp_vec;
            }
            // cout << "Completed a pass!" << endl;
            passcount++;
            if (passcount/1000 == passcount*1.00/1000)
            {
                cout << temp_vec.size() << " ";
                for (auto p : temp_vec)
                {
                    cout << p << " ";
                }
            cout <<endl;
            }
        }
    }
    // print result
    cout << result_vec.size() << " ";
    for (auto p : result_vec)
    {
        cout << p << " ";
    }
    cout << endl;
    // debug
    cout<< clientScore << endl;
}

int main()
{
    fastio;
    cin >> t;

    // inputting data
    for (int p = 0; p < t; p++)
    {
        int l;
        string s;
        vector<string> temp_vec;
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            cin >> s;
            temp_vec.push_back(s);
        }
        client_likes.push_back(temp_vec);
        // cout <<"successfully inputted like"<< endl;
        temp_vec.clear();
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            cin >> s;
            temp_vec.push_back(s);
        }
        client_dislikes.push_back(temp_vec);
        // cout <<"successfully inputted dislike"<< endl;
    }
    cout << "Calling algo" << endl;
    algo2();

    // algo 1.0: make a pizza acc to first client's likes and dislikes (put ALL their likes into the pizza and none of their dislikes), and calculate the no. of pizzas sold. Do same thing for ALL clients. Result will be the case with highest number of pizza sold

    // int temp_result, result = 0;
    // for (int i = 0; i < t; i++)
    // {
    //     temp_result = checkPizza(i, t, client_likes, client_dislikes);
    //     if(temp_result > result) result = i;
    // }

    // //print result

    // cout << client_likes[result].size()<< " ";
    // for(auto t1 : client_likes[result]) cout << t1 <<" ";

    // cout<<endl;
    return 0;
}
