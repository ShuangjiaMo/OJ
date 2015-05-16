#include <iostream>
using namespace std;
 
int main()
{	char str[100][6];
	int N, i, sen_1=0, sen_2=0; 
	bool result = true;
	
	cin >> N;
	for (i=0; i<N; ++i) cin >> str[i];
		
	for (i=0; i<N; ++i){
		switch(str[i][1]){
			case 'e': ++sen_1; break;
			case 'n': --sen_1; break;
			case 'f': if (str[i+1][1] != 'h') result = false; break;
			case 'h': if (str[i-1][1] != 'f') result = false; ++sen_2; break;
			default: if (sen_2 == 0) result = false; --sen_2;
		}
		
		if (sen_1 < 0) result = false;
	} 
	
	if (sen_1 != 0) result = false;
	
	if (result) cout << "YES";
	else cout << "NO"; 
	
	return 0;
}
