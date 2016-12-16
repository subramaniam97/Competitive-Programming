#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool f = (a * c ==  b * d);
    bool f1 = (a * d ==  b * c);
    bool f2 = (a * b ==  c * d);
    if(f || f1 || f2)
        cout<<"Possible\n";
    else
        cout<<"Impossible\n";
    return 0;
}
