#include <iostream>
using namespace std;

int main()
{	int n, res[3334]={0};
	
	cin >> n;
	res[0]=1;
	res[1]=1;
	res[2]=2;
	res[3]=4;
	
	for (int i=4; i<=n; i++)
	{
		res[i]=res[i-1];
		for (int j=0; j<i-1; j++)
		{
			res[i]+=res[i-2-j]*res[j];
			res[i]=res[i]%19301;
		}
	}
	
	cout << res[n];
	return 0;
}
