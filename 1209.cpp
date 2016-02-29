#include <iostream>
using namespace std;

int countOf1(int num)
{
	int count = 0;
	unsigned int flag = 1;

	while(flag)
	{
		if(num & flag)
		{
			count++;
		}

		flag = flag << 1;
	}
	return count;
}

int main()
{	int n, i, ans=0, num;
	
	cin >> n;
	for (i=0; i<n; ++i){
		cin >> num;
		ans += countOf1(num);
	}
	
	cout << ans;
	return 0;
}
