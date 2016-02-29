#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int i, j, k, count;
	string answer, code, temp;
	
	cin >> answer >> code;
	for (i=2; i<=answer.length(); ++i){
		if (answer.length()%i != 0) continue;
		
		temp = answer;
		count = 0;
		for (j=0; j<i; ++j){
			for (k=j; k<answer.length(); k+=i){
				temp[count] = answer[k];
				++count;
			}
		}
		
		if (temp == code){
			cout << i;
			return 0;
		}
	} 	
	
	cout << "No Solution";
	return 0;
}
