#include<bits/stdc++.h>
using namespace std;

string to_string(int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    return s;
}

string findPair(int n)
{
    int m = n % 8;
    if(m == 0)
        m = 8;
    if(m == 1)
        return to_string(n + 3) + "LB";
    if(m == 2)
        return to_string(n + 3) + "MB";
    if(m == 3)
        return to_string(n + 3) + "UB";
    if(m == 4)
        return to_string(n - 3) + "LB";
    if(m == 5)
        return to_string(n - 3) + "MB";
    if(m == 6)
        return to_string(n - 3) + "UB";
    if(m == 7)
        return to_string(n + 1) + "SU";
    if(m == 8)
        return to_string(n - 1) + "SL";
}

int main()
{
    string ans;
    int n, t;
    cin>>t;
    while(t--)
    {
        scanf("%d", &n);
        ans = findPair(n);
        cout<<ans<<endl;
    }
    return 0;
}
