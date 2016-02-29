#include <iostream>
using namespace std;
 
int main()
{	int n, i=0, j, k, num[600][600], len, type;
 
	cin >> n;
	while (i < n){
		cin >> len >> type;
		for (j=0; j<len; ++j){
			for (k=0; k<len; ++k){
				cin >> num[j][k];
			}
		}
		
		switch(type){
			case 0:{
				for (j=0; j<len; ++j){
					for (k=0; k<len; ++k){
						cout << num[j][len-k-1] << ' ';
					}
					cout << endl;
				}
				break;
			}
			
			case 1:{
				for (j=0; j<len; ++j){
					for (k=0; k<len; ++k){
						cout << num[len-j-1][k] << ' ';
					}
					cout << endl;
				}
				break;
			}
			
			default:{
				for (j=0; j<len; ++j){
					for (k=0; k<len; ++k){
						cout << num[k][j] << ' ';
					}
					cout << endl;
				}
			}			
		}	
		++i;
	}
	
	return 0;
}
