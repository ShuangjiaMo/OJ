#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int i;
	string a, b;
	
	cin >> a >> b;
	while (a.length() > b.length()) b = '0' + b;
	while (b.length() > a.length()) a = '0' + a;
	
	int c[a.length()+1];
	for (i=0; i<a.length()+1; ++i) c[i] = 0;
	
	for (i=a.length()-1; i>=0; --i){
		if (a[i] + b[i] + c[i+1] > '9' + '0'){
			c[i] = c[i] + 1;
			c[i+1] = a[i] + b[i] + c[i+1] - '5' - '5';
		}
		else c[i+1] = a[i] + b[i] + c[i+1] - '0' - '0';
	}
	
	if (c[0] == 1) cout << c[0];
	for (i=1; i<a.length()+1; ++i) cout << c[i];
	return 0;
}
