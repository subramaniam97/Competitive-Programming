#include<iostream>
using namespace std;

int main()
{
int t,i,j,h=0;
cin>>t;
char a[t][105];
for(i=0;i<t;i++)
{
cin>>a[i];
}
for(i=0;i<t;i++)
{
h=0;
for(j=0;a[i][j]!='\0';j++)
{
if(a[i][j]=='A'||a[i][j]=='D'||a[i][j]=='O'||a[i][j]=='P'||a[i][j]=='Q'||a[i][j]=='R')
h++;
else if(a[i][j]=='B')h+=2;
}
cout<<h<<endl;
}
return 0;
}