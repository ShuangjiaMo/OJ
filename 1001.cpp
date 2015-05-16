#include <iostream>
using namespace std;
 
int main()
{	int height_1, height_2, num, apple[1000], i, result = 0;
	
	cin >> height_1 >> height_2 >> num;	
	for (i=0; i<num; ++i) {
		cin >> apple[i];
		if (apple[i] <= height_1 + height_2) ++result;
	}
	
	cout << result;
	return 0;
}
