#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1005][1005]={0}, m, n;

int main()
{	string a, b;
	int i, j; 
	
	cin >> a >> b;
	m = a.length();
	n = b.length();
	
	for (i=1; i<=m; ++i){
		for (j=1; j<=n; ++j){
			if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	
	cout << dp[m][n];
	return 0;
}
