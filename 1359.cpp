#include <iostream>
#include <string>
using namespace std;

int main()
{	int i, ans=0;
	string str;
	
	getline(cin, str);
	for (i=0; i<str.length(); ++i){
		if (str[i] >= 'A' && str[i] <= 'Z'){
			ans += (str[i] - 'A' + 1) * (i + 1);
			continue;
		}
		if (str[i] >= 'a' && str[i] <= 'z'){
			ans += (str[i] - 'a' + 27) * (i + 1);
			continue;
		}
		if (str[i] == ' ') continue;	
	}
	
	cout << ans;
	return 0;
}
