#include <iostream>
#include <string> 
using namespace std;
 
int main()
{	string s[100], temp, func="", str;
	char ch=' ';
	int i, j, k, count=0, num; 
	
	while (true){
		getline(cin, temp);
		if (temp != "******"){
			s[count] = temp;
			++count;
		}
		else break;
	}
	
	while (ch != 'u'){
		cin >> func;
		ch = func[1];
		
		switch(ch){
			case 'i': {
				cin >> i >> j;
				if (i < 1 || j > count || i > j) cout << "Error!" << endl;
				else {
					for (k=i-1; k<j; ++k) cout << s[k] << endl;
				}
				break;
			}
			
			case 'n': {
				cin >> i >> j;
				cin.ignore();
				getline(cin, str);
				if (i > count || i < 1 || j > s[i-1].length()+1 || j < 1) cout << "Error!" << endl;
				else {
					s[i-1] = s[i-1].substr(0, j-1) + str + s[i-1].substr(j-1, s[i-1].length());
				}
				break;
			}
			
			case 'e': {
				cin >> i >> j >> num;
				if (i > count || i < 1 || j > s[i-1].length() || j < 1 || (j-1+num) > s[i-1].length()) cout << "Error!" << endl;
				else {
					s[i-1] = s[i-1].substr(0, j-1) + s[i-1].substr(j-1+num, s[i-1].length());
				}
				break;
			}
		}
	}
	
	for (i=0; i<count; ++i) cout << s[i] << endl;
	return 0;
}
