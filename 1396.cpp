#include <iostream>
using namespace std;

int main()
{	long long m, n, ans, count[10]={0}, last;
	
	cin >> m;
	while(m>0){
		cin >> n;
		if (n == 1){
			cout << 0 << endl;
			m--;
			continue;
		} 
		count[5] = n/5;
		last = n%5;
		
		if (last == 0){
			count[3] = 0;
			count[2] = 0;
			ans = 1;
		}
		else{
			while(last != 0){
				if (last%2 == 0){
					ans = 1;
					count[2] = last/2;
					count[3] = 0;
					ans += count[2]/3;
					last = 0;
				}
				else if (last%3 == 0){
					ans = 1;
					count[2] = 0;
					count[3] = last/3;
					ans += count[3]/2;
					last = 0;
				}
				else{
					count[5] -= 1;
					last += 5;
				}
			}
		}
			
		while (count[5] != 0){
			count[5]--;
			ans++;
			count[2]++;
			count[3]++;
			ans += count[2]/3;
			ans += count[3]/2;
		}
		
		cout << ans << endl;
		m--;
	}
	return 0;
}

