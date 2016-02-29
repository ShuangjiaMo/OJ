#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int N=0, i=0, sen_1=0, sen_2=0; 
	bool result = true;
	string str[1000], tmp;
	
	while (cin >> tmp){
		if (tmp=="begin" || tmp =="end" || tmp=="if" || tmp=="then" || tmp=="else"){
			str[i] = tmp;
			++i;
			++N;
		}
	}
		
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
	
	if (result) cout << "Match!";
	else cout << "Error!"; 
	
	return 0;
}
