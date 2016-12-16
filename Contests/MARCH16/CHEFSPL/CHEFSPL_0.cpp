#include<bits/stdc++.h>
using namespace std;

int f[26];

bool chkstr(string s)
{
    int v = s.length()/2;
    for(int i=0;i<v;i++)
    {
        if(s[i]!=s[i+v])return 0;
    }
    return 1;
}

bool chkstr1(string a, string b, char c)
{
    bool allowed=0;
    int p,q;
    p=0;
    q=0;
    for(;p<a.length(),q<b.length();)
    {
        if(a[p]!=b[q])
        {
            if(a[p]!=c&&b[q]!=c)return 0;
            if(a[p]==c)
            {
                if(allowed)return 0;
                q--;
                allowed=1;
            }
            else if(b[q]==c)
            {
                if(allowed)return 0;
                p--;
                allowed=1;
            }
        }
        p++;
        q++;
    }
    if(p!=a.length()||q!=b.length())return 0;
    return 1;
}

int main()
{
    bool ok,fine;
    int d;
    char c;
    string s;
    scanf("%d",&d);
    while(d--)
    {
        memset(f,0,sizeof(f));
        ok=fine=1;
        cin>>s;
        if(s.length()==1)
        {
            printf("NO\n");
            continue;
        }
        if(chkstr(s))
        {
            printf("YES\n");
            continue;
        }
        else
        {
            if(!(s.length()&1))
            {
                printf("NO\n");
                continue;
            }
        }
        for(int i=0;i<s.length();i++)f[s[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(f[i]&1)
            {
                if(!ok)
                {
                    fine=0;
                    break;
                }
                f[i]--;
                c='a'+i;
                ok=0;
            }
        }
        if((!fine)||ok)
        {
            printf("NO\n");
            continue;
        }

        int v=s.length()/2;
        string a,b;
        fine=0;
        a=b=s;

        a.erase(a.begin()+v,a.end());
        b.erase(b.begin(),b.begin()+v);
        if(chkstr1(a,b,c))fine=1;

        a=b=s;
        a.erase(a.begin()+v+1,a.end());
        b.erase(b.begin(),b.begin()+v+1);
        if(chkstr1(a,b,c))if(!fine)fine=1;

        if(fine)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
