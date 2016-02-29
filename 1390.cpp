#include <iostream>
#include <iomanip>
using namespace std;

double dp[1005][1005]={0};
const double p=1.0/36;

int main()
{	int n, i, j, ii, jj;
	cin >> n;
	
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++){
            dp[i][j]+=1.0;
            for (ii=1; ii<=6; ++ii){
                    for (jj=1; jj<=6; ++jj){
                        if(i-ii>=1 && j-jj>=1)
                            dp[i][j] += dp[i-ii][j-jj]*p;
                    }
                }
		}
	}
	
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << dp[n][n];
	return 0;
}
