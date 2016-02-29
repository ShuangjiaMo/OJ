#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int i, j, start, len, tem, n = 0;
	string a, b;
	
	cin >> a >> b;
	
	while (a.length() > b.length()) b = '0' + b;
	while (b.length() > a.length()) a = '0' + a;
	len = a.length() + b.length();
	start = len;
	
	int c[len];
	for (i=0; i<len; ++i) c[i] = 0;
	
	for (i=b.length()-1; i>=0; --i){
		for (j=a.length()-1; j>=0; --j){
			c[i+j+1] = (a[j]-'0') * (b[i]-'0') + c[i+j+1];
		}
	}
	
	for (i=len-1; i>0; --i){
		tem = c[i];
		c[i] = tem % 10;
		c[i-1] += (tem % 100) / 10;
		c[i-2] += tem / 100;
	}
	
	while(start == len){
		if (c[n] != 0) start = n;
		++n;
	}
	for (i=start; i<len; ++i) cout << c[i];
	return 0;
}
