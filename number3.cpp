#include<iostream>
using namespace std;
int main(){
    int n,l,r[3],d;
    cin>>n;
    if((n-1)%2==0){
        if (((n-1)/2)%3==0)
        {
            cout<<1<<" "<<(n-3)/2<<" "<<(n+1)/2 ;
        }
        else
            cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2 ;
        
    }
    else //n is even
    {
       l=n/2;
       if (l%3==0){
            cout<<1<<" "<<l-2<<" "<<l+1 ;

       }
       else if((l-1)%3==0){
           cout<<4<<" "<<l-2<<" "<<l-2 ;
       }
       else{
           cout<<2<<" "<<l-1<<" "<<l-1 ;
       }
       
       
        
    }
    
    return 0;
}