#include <iostream>
using namespace std;

int main()
{	int n, num[1050], i, j, k, tmp;
	bool judge;
	
	cin >> n;
	for (i=0; i<n; ++i) cin >> num[i];
	
	for (i=0; i<n; ++i){
		for (j=0; j<n; ++j){
			if (i==j) continue;
			if (num[i] > num[j]) tmp = num[i]/num[j];
			else tmp = num[j]/num[i];
			judge = true;
			
			for (k=0; k<n; ++k){
				if (num[k] == tmp){
					judge = false;
					break;
				}
			}
			if (judge) num[n++] = tmp;
		}
	}
	
	cout << n;
	return 0;
} 
