#include <iostream>
#include <string>
using namespace std;

int num[10000000]={0};

int main()
{
	int n, val, unit;
	bool flag=true;
	string str;

	cin >> n;
	while (n --){
		cin >> str;
		val = 0;
		for(int i=0; i<str.length(); i++)   {                                                
			if (str[i]>='A' && str[i]<='P'){
				unit = (str[i]-'A')/3 + 2; 
				val = 10*val + unit;
			}
			else if (str[i]>='R' && str[i]<='Y'){
				unit = (str[i]-'B')/3 + 2 ;
				val = 10*val + unit;
			}
			else if (str[i]>='0' && str[i]<='9'){
				unit = str[i] - '0';
				val = 10*val + unit;
			}
		}
		num[val]++;
	}
	for(int i=0; i<10000000; i++){
		if(num[i] >= 2){
			if (i/10000 > 99) cout << i/10000;
			else if (i/10000 > 9) cout << "0" << i/10000;
			else cout << "00" << i/10000;
		    cout << "-";
			if (i%10000 > 999) cout << i%10000;
			else if (i%10000 > 99) cout << "0" << i%10000;
			else if (i%10000 > 9) cout << "00" << i%10000;
			else cout << "000" << i%10000;
			cout << " " << num[i] << endl;
			flag = false;
		}
	}
	if (flag) cout << "No duplicates." << endl;
	return 0;
}
