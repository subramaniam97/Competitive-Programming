#include<iostream>
using namespace std;

int main()
{
    int n,a[100001],i,c,m,x;
    cin>>n;
    c=x=m=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=0)c++;
        else
        {
        	x=1;
            if(c>m)m=c;
            c=0;
        }
        if(x==0)m=c;

    }
    cout<<m;
    return 0;
}

