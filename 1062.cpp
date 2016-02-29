#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 9999999
using namespace std;

int n;
int a[1000005];
int b[1000005];
int dp[1000005]={0};
int ep[1000005]={0};
int c1[1000005];
int c2[1000005];
 
int main()
{
    for(int i=1;i<=1000004;++i)
    {
        c1[i]=INF;
        c2[i]=INF;
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",(a+i));
        b[n+1-i]=a[i];
    }
    for(int i=1;i<=n;++i)
    {
        *lower_bound(c1+1,c1+n+1,a[i])=a[i];
        dp[i]=lower_bound(c1+1,c1+n+1,INF)-(c1+1);
    }
    for(int i=1;i<=n;++i)
    {
        *lower_bound(c2+1,c2+n+1,b[i])=b[i];
        ep[i]=lower_bound(c2+1,c2+n+1,INF)-(c2+1);
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,dp[i]+ep[n+1-i]);
    }
    cout<<n-ans+1;
 
    return 0;
}
