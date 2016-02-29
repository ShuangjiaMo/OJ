#include <iostream>
using namespace std;
 
int main()
{	int N, i, j, result=0;
	char row[50][100];
	
	cin >> N; 
	cin.sync();
	
	for (i=0; i<N; ++i) cin >> row[i];
	
	for (i=0; i<N; ++i){
		for (j=0; j<100; ++j){
			if (row[i][j] == '(') ++result;
			if (row[i][j] == ')') --result;
		}
		
		if (result == 0 && row[i][0] == '(') cout << "YES" << endl;
		else cout << "NO" << endl;
		
		result = 0;
	}
	
	return 0;
}
