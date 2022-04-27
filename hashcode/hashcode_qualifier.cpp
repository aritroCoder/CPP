#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

// global vars
int c, p;
vector<pair<string, int>> c_name; // name and no of skills
vector<pair<string, int>> skill;  // skill name and level
vector<string> proj_name;
vector<pair<int, int>> req_days; // req days and serial num
vector<int> score;
vector<int> best_before;
vector<int> no_of_role;
vector<pair<string, int>> req_skills; // skill name and level requied

bool checkproject(int i){
    int sl_no = req_days[i].second;
    // string proj_output[no_of_role[sl_no]+1];
    vector<string> proj_output;
    // proj_output.push_back(to_string(p));
    // proj_output.push_back("\n");
    set<int> booked_members;
    set<int> members_to_lvl_up;
    proj_output.push_back(proj_name[sl_no]);
    proj_output.push_back("\n");
    //calculate the indexof starting of req_skills for this project using sl_no
    int temp = 0, skill_index = 0;
    while(temp < sl_no){
        skill_index += no_of_role[temp++];
    }

    for (int j = 0; j < no_of_role[sl_no]; j++)
    {
        string curr_role = req_skills[skill_index+j].first;
        int role_lvl = req_skills[skill_index+j].second;
        //search for compatible person in contributors (not consider mentoring)
        for (int k = 0; k < skill.size(); k++)
        {
            if(skill[k].first == curr_role && skill[k].second >= role_lvl && !binary_search(booked_members.begin(),booked_members.end(), k)){
                booked_members.insert(k);
                int nameindex = 0, skillindex = 0;
                while(skillindex < k){
                    skillindex += c_name[nameindex].second;
                    nameindex++;
                }
                proj_output.push_back(c_name[nameindex].first);
                proj_output.push_back(" ");
                if(skill[k].second == role_lvl || skill[k].second + 1 == role_lvl) members_to_lvl_up.insert(k);
            }
        }
        if(booked_members.size()<j+1) break; 
        
    }
    //check if all roles alloted successfully
    if(booked_members.size() == no_of_role[sl_no]){
        for(auto t: members_to_lvl_up){
            skill[t].second++;
        }
        for( auto t: proj_output){
            cout<<t;
        }
        return true;
    }
    return false;
}

int main()
{
    fastio;

    // getting inputs
    cin >> c >> p;
    for (int i = 0; i < c; i++)
    {
        string name;
        int skill_no;
        cin >> name >> skill_no;
        c_name.push_back(make_pair(name, skill_no));
        for (int j = 0; j < skill_no; j++)
        {
            string skill_name;
            int skill_level;
            cin >> skill_name >> skill_level;
            skill.push_back(make_pair(skill_name, skill_level));
        }
    }
    for (int i = 0; i < p; i++)
    {
        string p_name;
        int req_day, scor, b_before, n_o_role;
        cin >> p_name >> req_day >> scor >> b_before >> n_o_role;
        proj_name.push_back(p_name);
        req_days.push_back(make_pair(req_day, i));
        score.push_back(scor);
        best_before.push_back(b_before);
        no_of_role.push_back(n_o_role);
        for (int j = 0; j < no_of_role[i]; j++)
        {
            string sk_name;
            int sk_level;
            cin >> sk_name >> sk_level;
            req_skills.push_back(make_pair(sk_name, sk_level));
        }
    }
    // inputs taken successfully

    // order in which taskes will be performed is in ascending order of their required times, as per the greedy algorithm
    sort(req_days.begin(), req_days.end()); // sorting by first value, i.e the number of days required (ideally this order should be followed)]
    // array for storing project status information
    bool p_stat[p];
    int flg = 0;
    for (int i = 0; i < p; i++)
    {
        p_stat[i] = false;
    }
    cout << "Solution incoming"<<endl;
    cout << p << endl;
    while (flg < p)
    {
        for (int i = 0; i < p; i++)
        {
            if (p_stat[i])
                continue;

            else if (checkproject(i))
            {
                p_stat[i] = true;
                flg++;
                cout << endl;
                continue;
            }
        }
    }

    return 0;
}