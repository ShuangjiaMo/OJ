#include <iostream>
using namespace std;
 
int main()
{	long long bottle, num, i, total;
	
	cin >> bottle >> num;
	int change[num];
	for (i=0; i<num; ++i) cin >> change[i];
	
	total = bottle;
	for (i=0; i<num; ++i){
		if (bottle < change[i]){
			cout << total << ' ' << bottle;
			return 0;
		}
		
		total += bottle/change[i];
		bottle = bottle/change[i] + bottle%change[i];
	}
	
	while(bottle >= change[num-1]){
		total += bottle/change[num-1];
		bottle = bottle/change[num-1] + bottle%change[num-1];		
	}
	cout << total << ' ' << bottle;
	return 0;	
}
