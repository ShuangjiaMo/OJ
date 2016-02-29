#include <iostream>
#include <math.h>
using namespace std;

int main()
{	int n, i=2, count;
	bool find=false;
	
	cin >> n;
	
	cout << n << '=';
	while (n != 1){
		if (i>int(sqrt(double(n)))+1){
			cout << n << "(1)";
			break;
		}
		
		count = 0; 
		while (n%i == 0){
			n /= i;
			count++;
			find = true;
		}
		
		if (count != 0){
			cout << i << '(' << count << ')';
		}
		i++;
	}

	return 0;
}
