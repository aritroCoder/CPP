#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int a=10;
    int* p=&a;
    int** pp= &p;
    cout <<hex<<pp;
    return 0;
}