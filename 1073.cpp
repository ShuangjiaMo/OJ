#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int i, j, k, n, mark[105], dp[105][105]={0}, ans=0;
	
	cin >> n;
	for (i=0; i<n; ++i) cin >> mark[i];

	for(j=1; j<n; j++){
		for(i=0; i<n; i++){
			for(k=i; k<i+j; k++){
				dp[i][(i+j)%n] = max(dp[i][(i+j)%n], dp[i][k%n] + dp[(k+1)%n][(i+j)%n] + mark[i]*mark[(k+1)%n]*mark[(i+j+1)%n]);				
			}
		}
	}
	
	for(i=0; i<n; i++) ans = max(dp[i][(i+n-1)%n], ans);
	cout << ans;
	return 0;
} 
