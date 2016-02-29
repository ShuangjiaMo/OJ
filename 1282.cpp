#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, dp[2005][2005]={0}, least[2005][2005]={0}, a[2005], tmp[2005], ans=1<<30;

void quickSort(int s[], int l, int r)
{
	if (l < r)
	{      
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x)
				j--; 
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x)
				i++; 
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i-1); 
		quickSort(s, i+1, r);
	}
}

void sol()
{	int i, j, k;
	
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++){
			dp[i][j] = least[i-1][j] + abs(a[i-1]-tmp[j-1]);
            if(j == 1) least[i][j] = dp[i][j];
            else least[i][j] = min(dp[i][j],least[i][j-1]);
		}
	}
	
	for (i=1; i<=n; i++) ans = min(ans, dp[n][i]);
}
      

int main()
{	int i, t;
	
	cin >> n;
	for (i=0; i<n; i++){
		cin >> a[i];
		tmp[i] = a[i];
	}
	quickSort(tmp, 0, n-1);
	
	sol();
	for (i=0; i<n/2; i++){
		t = tmp[i];
		tmp[i] = tmp[n-i-1];
		tmp[n-i-1] = t;
	}
	sol();
	
	cout << ans;
	return 0;
} 
