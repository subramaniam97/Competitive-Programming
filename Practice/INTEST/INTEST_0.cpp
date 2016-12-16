#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,k,cnt=0,no;
    scanf("%d%d",&n,&k);
    while(n--)
    {
              scanf("%d",&no);
              if(no%k == 0)
              {
                            
              cnt++;
              }
              
             
    }
    printf("%d",cnt);
    
    return 0;
}