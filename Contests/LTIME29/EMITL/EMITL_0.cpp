#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,c[27],f;
    string s;
    cin>>t;
    while(t--)
    {
        f=0;
        memset(c,0,sizeof(c));
        cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            if((!f)&&s[i]!='L'&&s[i]!='T'&&s[i]!='I'&&s[i]!='M'&&s[i]!='E')f=1;
            c[s[i]-64]++;
        }
        if(f==0)
        {
            if(c[5]>=1&&c[12]>=2&&c[9]>=2&&c[13]>=2&&c[20]>=2)cout<<"YES\n";
            else if(c[5]==1&&c[12]==1&&c[9]==1&&c[13]==1&&c[20]==1)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else
        {
             if(c[5]>=2&&c[12]>=2&&c[9]>=2&&c[13]>=2&&c[20]>=2)cout<<"YES\n";
             else cout<<"NO\n";
        }
        
    }
    return 0;
}
