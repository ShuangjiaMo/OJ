#include <iostream>   
#include <cmath>  
  
using namespace std;  
#define MAXN 1001  
  
int R;  
int tri[MAXN][MAXN];  
int dp[MAXN][MAXN]; 
  
int main(){  
    cin>>R;  
    for(int i = 1; i <= R; i++){  
        for(int j = 1; j <= i; j++){  
            cin>>tri[i][j];  
        }  
    }  
    dp[1][1] = tri[1][1];  
    for(int i = 1; i <= R; i++){  
        for(int j = 1; j <= i; j++){  
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];  
        }  
    }  
    int maxnum = 0;  
    for(int i = 1; i <= R; i++){  
        if(dp[R][i] > maxnum )  
            maxnum = dp[R][i];  
    }  
    cout<<maxnum<<endl;  
      
    return 0;  
}
