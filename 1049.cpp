#include <iostream>
using namespace std;

int main()
{	int t, i, train, stop, seq[1005], pass, station[1005], top;
	
	cin >> t;
	while (t>0){
		cin >> train >> stop;
		for (i=0; i<train; ++i) cin >> seq[i];
		top = 0;
		pass = 0;
		
		for (i=0; i<train; ++i){
			while (top > 0){
				if (station[top-1] == seq[pass]){
					pass++;
					top--;
				}
				else break;
			}	
		
			if (seq[pass] == i){
				pass++;
				continue;
			}
			
			if (top < stop){
				station[top] = i;
				top++;
			}
			else break;
		}
		
		while (top > 0){
			if (station[top-1] == seq[pass]){
				pass++;
				top--;
			}
			else break;
		}
		
		if (pass == train) cout << "YES" << endl;
		else cout << "NO" << endl;
		t--;
	}
	
	return 0;
}
