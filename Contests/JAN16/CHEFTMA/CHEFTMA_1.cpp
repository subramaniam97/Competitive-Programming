#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

int n,k,m,a[100001],b[200001];
bool chk[200001];
ll r;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,x,p;
    cin>>t;
    while(t--)
    {
        r=0;
        memset(chk,0,sizeof(chk));
        cin>>n>>k>>m;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            cin>>x;
            a[i]-=x;
        }
        for(i=0;i<(m+k);i++)
        {
            cin>>b[i];
        }
        sort(b,b+m+k);
        for(i=0;i<n;i++)
        {
            p=lower_bound(b,b+m+k,a[i])-b;
            if(p<m+k&&b[p]==a[i])
            {
                if(chk[p]==0)
                {
                    if(b[p]==a[i])
                        {
                          while(p<m+k&&b[p]==a[i]&&chk[p]==0)p++;
                            if(p>0)p--;
                        }

                    a[i]=0;
                    chk[p]=1;
                }

                else
                {
                    while(p>=0&&chk[p]==1)p--;
                        if(p>=0)
                        {
                            a[i]-=b[p];
                             chk[p]=1;
                        }
                }
            }
            else
            {
                p--;
                if(p>=0)
                {
                    if(chk[p]==0)
                    {
                        if(b[p]==a[i])
                        {
                          while(p<m+k&&b[p]==a[i]&&chk[p]==0)p++;
                            if(p>0)p--;
                        }
                        a[i]-=b[p];
                        chk[p]=1;
                    }
                    else
                    {
                        while(p>=0&&chk[p]==1)p--;
                        if(p>=0)
                        {
                            a[i]-=b[p];
                            chk[p]=1;
                        }
                    }
                }

            }
            r+=a[i];
        }

        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
