#include <iostream>
using namespace std;

int main()
{	int i, j, n, ans=0, l=0, tmp;
	
	cin >> n;
	int len[n];
	for (i=0; i<n; ++i){
		cin >> len[i];
		l += len[i];
	}
	
	if (l%2 == 1){
		cout << 0;
		return 0;
	}
	
	for (i=0; i<n; ++i){
		tmp = 0;
		for (j=i; j<i+n; ++j){
			tmp += len[j%n];
			if (tmp == l/2){
				ans++;
				break;
			}
		}
	}
	
	ans /= 2;
	cout << ans*(ans-1)/2;
	return 0;
}
