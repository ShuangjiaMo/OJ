#include <iostream>
using namespace std;
 
int main()
{	int N, i, j, ans=0;
	
	cin >> N;
	int len[N][2];
	for (i=0; i<N; ++i) cin >> len[i][0] >> len[i][1];
	
	for (i=0; i<N; ++i){
		ans = ans + len[i][1] - len[i][0];
		for (j=0; j<i; ++j){
			if (len[i][0] >= len[j][0] && len[i][0] <= len[j][1] && len[i][1] > len[j][1]){
				ans = ans - len[j][1] + len [i][0];
				len[i][0] = len[j][1];
				continue;
			}
			if (len[i][1] >= len[j][0] && len[i][1] <= len[j][1] && len[i][0] < len[j][0]){
				ans = ans - len[i][1] + len [j][0];
				len[i][1] = len[j][0];
				continue;
			}
			if (len[i][0] >= len[j][0] && len[i][0] <= len[j][1] && len[i][1] >= len[j][0] && len[i][1] <= len[j][1]){
				ans = ans - len[i][1] + len [i][0];
				len[i][0] = len[i][1];
				continue;
			}
			if (len[i][0] < len[j][0] && len[i][1] > len[j][1]){
				ans = ans - len[j][1] + len[j][0];
				len[j][0] = len[j][1];
				continue;
			}
		}
	}
	
	cout << ans;
	return 0;
}
