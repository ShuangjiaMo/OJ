#include <iostream>
using namespace std;

int main()
{	int n, m, i, j, start=0, judge, sum=0;
	
	cin >> n >> m;
	int how[m][2], monkey[10000];
	for (i=0; i<n; ++i) monkey[i] = i + 1;
	for (i=0; i<m; ++i){
		cin >> judge;
		if (judge == 0){
			cin >> how[i][0];
			how[i][1] = -1;
		}
		else cin >> how[i][0] >> how[i][1];
	}
	
	for (i=0; i<m; ++i){
		start = (start+how[i][0]-1)%n;
		if (how[i][1] == -1){
			for (j=start; j<n; ++j) monkey[j] = monkey[j+1];
			--n;
		}
		else{
			for (j=n; j>start; --j) monkey[j] = monkey[j-1];
			monkey[start+1] = how[i][1];
			++start;
			++n;
		}
	}
	
	for (i=0; i<n; ++i) sum+=monkey[i];
	cout << sum;
	return 0;
}
