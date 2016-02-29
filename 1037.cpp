#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	int n, m, i, j, start=0, num=0;
	
	cin >> n >> m;
	int high[n], low[m];
	for (i=0; i<n; ++i) cin >> high[i];
	for (i=0; i<m; ++i) cin >> low[i];
	
	sort(high, high+n, greater<int>());
	sort(low, low+m, greater<int>());
	
	for (i=0; i<n; ++i){
		for (j=start; j<m; ++j){
			if (high[i] > low[j]){
				++num;
				start = j + 1;
				break;
			}
		}
	}
	
	cout << num+n;
	return 0;
}
