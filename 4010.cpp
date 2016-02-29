#include <iostream>
using namespace std;

int main()
{	int i, j, n, start=0, last=0, round=1, min, ans, tmp, len;
	
	cin >> n;
	int kid[n][2];
	for (i=0; i<n; ++i){
		cin >> kid[i][0];
		kid[i][1] = i+1;
	}
	len = n;
	
	while (len > 1){
		min = 1000000;
		
		if (round%2 == 1){
			for (i=start; i<start+len; ++i){
				if (kid[i%len][0] < min){
					min = kid[i%len][0];
					tmp = i%len;
				}
			}
			start = tmp;
			
			for (i=0; i<len; ++i) kid[i][0] -= min;
			for (i=(start+1)%len; i!=last; i=(++i)%len) kid[i][0]++;
		}
		
		if (round%2 == 0){
			start--;
			last--;
			if (start<0) start+=len;
			if (last<0) last+=len;
			for (i=start; i>start-len; --i){
				if (kid[(i+len)%len][0] < min){
					min = kid[(i+len)%len][0];
					tmp = (i+len)%len;
				}
			}
			start = tmp;
			
			for (i=0; i<len; ++i) kid[i][0] -= min;
			for (i=(last+1)%len; i!=start; i=(++i)%len) kid[i][0]++;
		}
		
		for (i=start; i<len-1; ++i){
			kid[i][0] = kid[i+1][0];
			kid[i][1] = kid[i+1][1];
		}
		if (kid[len-1][0] == 0) start = 0;
		
		last = start;
		len--;
		round++;
	}
	
	cout << kid[0][1];
	return 0;
}


