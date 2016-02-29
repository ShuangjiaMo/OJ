#include <iostream>
#include<algorithm>
using namespace std;

int dp[1005][1005]={0};

int main()
{	int n, i, j, tmp, ans=0;
	
	cin >> n;
	int num[n];
	for (i=1; i<=n; i++) cin >> num[i];
	
	for (i=1; i<=n; i++){
		for (j=0; j<=i; j++){
			if (num[i] == i-j) tmp = dp[i-1][j] + 1;
			else tmp = dp[i-1][j];
			dp[i][j] = max(tmp, dp[i-1][j-1]);
		}
	}
	
	for (j=0; j<=n; j++) ans = max(ans, dp[n][j]);
	cout << ans;
	return 0;
}
