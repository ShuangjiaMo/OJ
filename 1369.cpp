#include <iostream>
using namespace std;

int jump(int n, int s, int l)
{
	if(n==0) return 0;
	else if(n==s) return 1;
	else if(n==l && l%s != 0) return 1;
	else if(n==l && l%s == 0) return 2;
	else if(n>l) return jump(n-s, s, l)+jump(n-l, s, l);

}

int main()
{	int n, a, b;
	long long ans;
	cin >> n >> a >> b;
	if (a >= b) ans = jump(n, b, a);
	else ans = jump(n, a, b);
	cout << ans;
}
