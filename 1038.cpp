#include <iostream>
using namespace std;

int main()
{	int n, i, j, tmp, start=0;
	
	cin >> n;
	int k[n-1], monkey[n];
	for (i=0; i<n-1; ++i){
		cin >> k[i];
		monkey[i] = i + 1;
	}
	
	for (i=0; i<n-1; ++i){
		for (j=(start+k[i]-1)%(n-i); j<n-i; ++j) monkey[j] = monkey[j+1];
		start = (start+k[i]-1)%(n-i);
	}
	
	cout << monkey[0];
	return 0;
}
