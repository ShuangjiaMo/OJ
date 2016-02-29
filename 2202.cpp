#include <iostream>
#include <algorithm>
using namespace std;

int man[1005][1005], dp[1005][1005]={0};

int main()
{	int k, n, m, i, j;
	
	cin >> k;
	while (k--){
		cin >> n >> m;
		for (i=1; i<=n; i++){
			for (j=1; j<=m; j++){
				cin >> man[i][j];
			}
		}
		
		for (i=1; i<=n; i++){
			for (j=1; j<=m; j++){
				if (i==1) dp[i][j] = dp[i][j-1] + man[i][j];
				else if (j==1) dp[i][j] = dp[i-1][j] + man[i][j];
				else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + man[i][j];
			}
		}
		
		if (dp[n][m] <= 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}
