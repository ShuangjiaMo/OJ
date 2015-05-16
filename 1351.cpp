#include <iostream>
using namespace std;
 
int main()
{	int N, i, j, temp;
	cin >> N;
    bool num[N+1];
 
	for (i=2; i<=N; ++i) num[i] = true;
	for (i=2; i<=N; ++i){
		if (not num[i]) continue;
		for (j=2; j*i<=N; ++j) num[j*i] = false;
	}
	
	temp = N/2 + N%2;
	while (temp < N){
		if (num[temp] && num[N-temp]){
			cout << N-temp << ' ' << temp;
			return 0;
		}
		else ++temp;
	}
	
	cout << "NO";
	return 0;
}
