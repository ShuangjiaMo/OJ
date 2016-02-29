#include <iostream>
using namespace std;
 
int main()
{	int  V, N, i, max_i, result = 0;
	double max;	
	
	cin >> V >> N;
	double c[N], w[N];
	
	for (i=0; i<N; ++i) cin >> c[i] >> w[i];
	
	while (V > 0){
		for (i=0; i<N; ++i){
			if (c[i] <= V && w[i]/c[i] > max){
				max = w[i]/c[i];
				max_i = i;
			}
		}
		
		V -= c[max_i];
		if (V >= 0) result += w[max_i];
	}
	
	cout << result;
	return 0;
}
