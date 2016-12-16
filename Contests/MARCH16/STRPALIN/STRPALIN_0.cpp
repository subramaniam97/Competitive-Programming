#include<bits/stdc++.h>
using namespace std;

bool f[26];

int main()
{
    int t;
    bool done=0;
    string a,b;
    scanf("%d",&t);
    while(t--)
    {
        done=0;
        memset(f,0,sizeof(f));
        cin>>a>>b;
        for(int i=0;i<a.length();i++)f[a[i]-'a']++;
        for(int i=0;i<b.length();i++)
        {
            if(f[b[i]-'a']>=1)
            {
                printf("Yes\n");
                done=1;
                break;
            }
        }
        if(done)continue;
        printf("No\n");
    }
    return 0;
}
