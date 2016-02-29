#include <iostream>
#include <algorithm>
using namespace std;

int map[55][55]={0},dp[55][55][55][55]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>map[i][j];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++){
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l], dp[i-1][j][k][l-1]), max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1])) + map[i][j]+map[k][l];
                    if(i==k&&j==l) dp[i][j][k][l]-=map[i][j];
                }
    
    cout<<dp[n][m][n][m]<<endl;
    return 0;
}
