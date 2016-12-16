#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r;
    cout<<"1\n3 1 2 2\n3 3 4 4\n";
    fflush(stdout);
    cin>>r;
    if(r == 0) cout<<"2\n5\n";
    else if(r == 1) cout<<"2\n1\n";
    else if(r == -1) cout<<"2\n3\n";
    else if(r == 2) cout<<"2\n2\n";
    else if(r == -2) cout<<"2\n4\n";
    return 0;
}
