#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

//global vars
vector<string> liked_components;
vector<string> disliked_components;
int t;

//algorithm functions

bool checksubset(vector<string> A, vector<string> B){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return includes(A.begin(), A.end(), B.begin(), B.end());
}

void unique_elements(vector<string>& vec)
{
    sort(vec.begin(), vec.end());

    auto iter = unique(vec.begin(), vec.end());

    vec.erase(iter, vec.end());
}

int check(vector<string> &v){
    int pizzasell = 0;
    for (int i = 0; i < t; i++)
    {
        if( checksubset(v, client_likes[i]) && (find_first_of (disliked_components.begin(), disliked_components.end(), v.begin(), v.end()) == disliked_components.end()) ){
            //checking if client_dislikes and v are disjoint or not
            pizzasell++;
        }
    }
    return pizzasell;
}

void algo2(){
    //remove duplicates entries from giant vectors
    unique_elements(liked_components);
    unique_elements(disliked_components);
        //for debug
        // cout <<"disliked Items:"<<endl;
        // for(auto g: disliked_components){
        //     cout<< g<<endl;
        // }
    int clientScore = 0;
    int m=0;
    vector<string> temp_vec;
    vector<string> result_vec;
    for ( m = 0; m < liked_components.size(); m++)
    {
        temp_vec.clear();
        for (int n = m; n < liked_components.size(); n++)
        {
            temp_vec.push_back(liked_components[n]); //create all possible subset of the vector to test
        }
        if(check(temp_vec)>clientScore){
            clientScore = check(temp_vec);
            result_vec = temp_vec;
        }
    }
    //print result
    cout<<result_vec.size()<<" ";
    for(auto p : result_vec){
        cout << p;
    }
    cout <<endl;
}

//main 
int main()
{
    fastio;
    cin >> t;
    
    //inputting data
    for(int p=0; p<t; p++)
    {
       int l;
       string s;
       cin >> l;
       for (int i = 0; i < l; i++)
       {
           cin >> s;
           liked_components.push_back(s);
       }
            //debug line follows
            cout <<"successfully inputted like"<< endl;
       cin >> l;
       for (int i = 0; i < l; i++)
       {
           cin >> s;
           disliked_components.push_back(s);
       }
            //debug line follows
            cout <<"successfully inputted dislike"<< endl;
       
    }
    algo2();
    return 0;
}