#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{	int n, k, i, j, min=1000000000, l_max, count;
	
	cin >> n >> k;
	int chain[n];
	
	for (i=0; i<n; ++i) scanf("%d", &chain[i]);
	
	for (i=0; i<n; ++i){
		l_max = 0;
		count = 0;
		for (j=i; j<i+k; ++j){
			if (chain[j%n] > l_max){
				l_max = chain[j%n];
				count = 0;
			}
			if (chain[j%n] == l_max) ++count;
		}

		if (l_max < min) min = l_max;
		while (count > 0){
			if (chain[(i+k)%n] >= l_max){
				i+=k+1;
				break;
			}
			if (chain[(i+k)%n] < l_max && chain[i%n] == l_max){
				--count;
			}
			++i;
		}
		--i;
	}
	
	cout << min;
	return 0;
}
