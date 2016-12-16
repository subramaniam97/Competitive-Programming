#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

unsigned int a,b,s,t;
unsigned int w[1<<26];

int main()
{
    ios_base::sync_with_stdio(0);
    ll q,i,r=0;
        cin>>q>>s>>a>>b;
        while(q--)
        {
            t=s;
            if(s&1)
            {
                s>>=1;
                if(!(w[s>>5]&(1<<(s&31))))
                {
                    r+=s;
                    w[s>>5]|=(1<<(s&31));
                }

            }
            else
            {
                s>>=1;
                if(w[s>>5]&(1<<(s&31)))
                {
                    r-=s;
                    w[s>>5]^=(1<<(s&31));
                }
            }
            s=a*t+b;
        }
        cout<<r<<endl;
    return 0;
}


// ^_^ \\
