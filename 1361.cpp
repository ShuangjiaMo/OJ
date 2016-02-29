#include <iostream>
#include <string>
using namespace std;

int main()
{	int i, j, n, count=0, weekend=0;
	string ans[1000];
	bool judge;
	
	cin >> n;
	cin.ignore();
	string str[n], day[n];
	for (i=0; i<n; ++i) getline(cin, str[i]);
	
	for (i=0; i<n; ++i){
		day[i] = str[i].substr(str[i].rfind(' ')+1, str[i].length()-1);
	}
	
	for (i=0; i<n; ++i){
		judge = true;
		
		if (str[i].substr(0, 5) == "Today"){
			for (j=0; j<count; j++){
				if (day[i] == ans[j]){
					judge = false;
					break;
				}
			}
			
			if (judge){
				ans[count] = day[i];
				++count;
			}
			
			continue;
		}
		
		if (str[i].substr(0, 9) == "Yesterday"){
			for (j=0; j<count; j++){
				if (day[i] == ans[j]){
					judge = false;
					break;
				}
			}
			
			if (judge){
				for (j=0; j<i; ++j){
					if (day[i] == day[j]){
						ans[count] = day[i];
						count++;
						break;
					}
				}
			}
			
			continue;
		}
		
		if (str[i].substr(0, 8) == "Tomorrow"){
			for (j=0; j<count; j++){
				if (day[i] == ans[j]){
					judge = false;
					break;
				}
			}
			
			if (judge){
				for (j=i+1; j<n; ++j){
					if (day[i] == day[j]){
						ans[count] = day[i];
						count++;
						break;
					}
				}
			}
		}
	}
	
	for (i=0; i<count; ++i){
		if (ans[i][ans[i].length()-2] == 'd') ++weekend;
	}
	
	cout << count << ' ' << weekend;
	return 0;
}
