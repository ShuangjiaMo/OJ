#include <iostream>
using namespace std;

int m, cash[9]={1,2,6,24,120,720,5040,40320,362880}, ans=100000;

void charge(int left, int num){
	int i, start;
	if (left == 0){
		if (num < ans) ans = num;
		return;
	}
	if (num >= ans) return;
	
	for (i=0; i<9; ++i){
		if (left>=cash[i] && left<=cash[i+1]){
			start = i;
			break;
		}
	}
	charge(left%cash[start], num+left/cash[start]);
	charge(cash[start+1]-left, num+1);
} 

int main()
{	cin >> m;
	
	charge(m, 0);
	cout << ans;
	return 0;
}
