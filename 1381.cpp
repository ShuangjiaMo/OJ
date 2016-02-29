#include <iostream>
using namespace std;

int main()
{	int i, j, num[10]={6,2,5,5,4,5,6,3,7,6}, n, ans=0, ti, tj, ts, sum;
	
	cin >> n;
	
	for (i=0; i<1000; ++i){
		for (j=i; j<1000; ++j){
			ti = i;
			tj = j;
			ts = i+j;
			sum = 3;
			
			if (i == 0) sum += num[0];
			if (j == 0) sum += num[0];
			if (i+j == 0) sum += num[0];
			while (ti != 0){
				sum += num[ti%10];
				ti /= 10;
			}
			while (tj != 0){
				sum += num[tj%10];
				tj /= 10;
			}
			while (ts != 0){
				sum += num[ts%10];
				ts /= 10;
			}
			
			if (sum == n){
				if (i == j) ans++;
				else ans+=2;
			}
		}
	}
	
	cout << ans;
	return 0;
}
