#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{	int n, i, l, v, tmp, max_l = 0;
	double ans;
	
	cin >> n >> l >> v;
	int dir[n], pos[n];
	for (i=0; i<n; ++i) cin >> pos[i];
	for (i=0; i<n; ++i) cin >> dir[i];
	
	for (i=0; i<n; ++i){
		if (dir[i] == 0) tmp = pos[i];
		else tmp = l - pos[i];
		
		if (tmp > max_l) max_l = tmp;
	}
	
	ans = double(max_l)/double(v);
	printf("%.3f\n", ans);
	return 0;
}
