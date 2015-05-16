#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int rule[200], N, i, j;
	string book[100], result; 
	
	cin >> N;
	cin.ignore();
	for (i=0; i<N; ++i) getline(cin, book[i]);
	
	for (i=0; i<N-1; ++i){
		cin >> rule[2*i] >> rule[2*i+1];
		
		result = book[rule[2*i+1]-1] + ' ' + book[rule[2*i]-1];
		for (j=0; j<i+1; ++j){
			if (rule[2*j]==rule[2*i] || rule[2*j]==rule[2*i+1] || rule[2*j+1]==rule[2*i] || rule[2*j+1]==rule[2*i+1]){
				book[rule[2*j]-1] = result;
				book[rule[2*j+1]-1] = result;
			}
		}
	}
	
	cout << result;
	return 0;
}
