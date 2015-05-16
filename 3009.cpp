#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int i, j;
	string a, b;
	
	cin >> a >> b;
	
	if (a == b){
		cout << "YES";
		return 0;
	}
	for (i=0; i<b.length(); ++i){
		for (j=i+1; j<b.length(); ++j){
			if (b.substr(0, i) + b[j] + b.substr(i+1, j-i-1) + b[i] + b.substr(j+1, b.length()-j-1) == a){
				cout << "YES";
				return 0;
			}
		}
	}
	
	cout << "NO";
	return 0;
}
