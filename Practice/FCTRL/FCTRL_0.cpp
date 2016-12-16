#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int t,n[100005],i,g=0,p=1;
cin>>t;
for(i=0;i<t;i++)
{
cin>>n[i];
}
for(i=0;i<t;i++)
{
g=0;
p=1;
while(n[i]>=pow(5.00,p))
{
g+=n[i]/pow(5.00,p);
p++;
}
cout<<g<<endl;
}
return 0;
}  
 