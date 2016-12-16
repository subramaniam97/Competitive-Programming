#include<iostream>
using namespace std;
int main()
{
int t,i,n,q,g,k,j;
cin>>t;

 
while(t--)
{
cin>>g;
for(j=0;j<g;j++)
{
cout<<endl;
cin>>i;
cin>>n;
cin>>q;
if(n%2==0)
{
k=(n/2);
if(q==1||q==2) cout<<k;
}
else
{
if(q==1&&i==2) k=(n/2)+1;
if(q==1&&i==1) k=(n/2);
if(q==2&&i==1) k=(n/2)+1;
if(q==2&&i==2) k=(n/2);
cout<<k;
}
}
}
return 0;
} 