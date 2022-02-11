#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, m, flg, i;
    bool valid=false;
    cin>>n>>m;
    long long int  class_min[n], alarm_step[m];
    for(i=0;i<n;i++){
        cin>>class_min[i];
    }
    for(i=0;i<m;i++){
        cin>>alarm_step[i];
    }
    for(i=0; i<m;i++){
        flg=0;
        for(int j=0; j<n-1;j++){
            if((class_min[j+1]-class_min[j])%alarm_step[i] == 0) flg++;
        }
        if(flg==n-1){
            cout<<"YES"<<endl;
            valid=true;
            break;
        }
    }
    if(!valid){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<class_min[0]<<" "<<i+1<<endl;

    return 0;
}