#include<iostream>
using namespace std;
int main(){
    int a, d=0,count=1;
    cin>>a;
    while(d<a){
        d+=count++;
        cout<<" "<<d<<" "<<count<<endl;
    }
    if (d==a)
    {
        cout<<count ;
    }
    else if(d>a){
        while(d>a){
            d--;

            count++;
            cout<<" "<<d<<" "<<count<<endl;
        }
        cout<<count ;
    }
    return 0;
}