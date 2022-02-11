#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n,row=0,col=0,c;
    cin>>n;
    c=n; //create a copy of var n
    int* arr = new int[(2n-1) * (2n-1)];
    for (int i = n-1; i >=0; i--)
    {
        if(row==(2n+1)/2 + 1){
            break; //end condition
        }
            for (int k = 0; k < 2i-1; k++)
            {
                arr[row][col+k]=c ;
                arr[i-row][col+k]=c ;
            }
            for (int k = 0; k < 2i-1; k++)
            {
                arr[row+k][col]=c ;
                arr[row+k][i-col]=c ;
            }
            row++;
            col++;
            c--;
    }
    
    return 0;
}