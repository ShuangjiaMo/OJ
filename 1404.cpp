#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{	int i, j, loc, l, len=0, kill=0, high=-1, hit, blen=0;
	string sen, name[100000], tmp, t, s, buff[100000];
	bool find;

	getline(cin, sen);
	while(sen != "#DOTA2#"){
		loc = sen.find(" ");
		tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
		sen = sen.substr(loc+1);
		
		l = sen.find(" ");
		t = sen.substr(l+1, sen.substr(l+1).find(" "));
		if (t!="hits" && t!="receives" && t!="loses" && t!="is"){
			tmp = tmp + " " + t;
			sen = sen.substr(l+1);
		}
		
		find = false;
		for (i=0; i<len; i++){
			if (tmp == name[i]){
				find = true;
				break;
			}
		}
		if (not find) name[len++] = tmp;
		
		loc = sen.find(" ");
		tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
		sen = sen.substr(loc+1);
		
		switch(tmp[0]){
			case 'h':{
				loc = sen.find(" ");
				tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
				sen = sen.substr(loc+1);
				
				l = sen.find(" ");
				t = sen.substr(l+1, sen.substr(l+1).find(" "));
				if (t!="for" && t!="with"){
					tmp = tmp + " " + t;
					sen = sen.substr(l+1);
				}
				
				find = false;
				for (i=0; i<len; i++){
					if (tmp == name[i]){
						find = true;
						break;
					}
				}
				if (not find) name[len++] = tmp;
				
				loc = sen.find(" ");
				tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
				sen = sen.substr(loc+1);
				if (tmp == "for"){
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
					sen = sen.substr(loc+1);
					
					stringstream ss;
					ss << tmp;
					ss >> hit;
					high = max(high, hit);
				}
				break;
			}
			case 'r':{
				while (tmp != "buff" && tmp != "debuff"){
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
					sen = sen.substr(loc+1);
				}
				if (tmp == "buff"){
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
					sen = sen.substr(loc+1);
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find("."));
					
					find = false;
					for (i=0; i<len; i++){
						if (tmp == name[i]){
							find = true;
							break;
						}
					}
					if (not find) name[len++] = tmp;
					
					find = false;
					for (i=0; i<blen; i++){
						if (tmp == buff[i]){
							find = true;
							break;
						}
					}
					if (not find) buff[blen++] = tmp;
				}
				else{
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
					sen = sen.substr(loc+1);
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find("."));
					
					find = false;
					for (i=0; i<len; i++){
						if (tmp == name[i]){
							find = true;
							break;
						}
					}
					if (not find) name[len++] = tmp;
				}
			}
			case 'l':{
				break;
			}
			case 'i':{
				kill++;
				while (tmp != "by"){
					loc = sen.find(" ");
					tmp = sen.substr(loc+1, sen.substr(loc+1).find(" "));
					sen = sen.substr(loc+1);
				}
				loc = sen.find(" ");
				tmp = sen.substr(loc+1, sen.substr(loc+1).find("!"));
				
				find = false;
				for (i=0; i<len; i++){
					if (tmp == name[i]){
						find = true;
						break;
					}
				}
				if (not find) name[len++] = tmp;
				break;
			}
		}
		getline(cin, sen);
	}
	
	cout << "#1:" << endl << len << endl;
	cout << "#2:" << endl << high << endl;
	cout << "#3:" << endl << kill << endl;
	cout << "#4:" << endl;
	if (blen == 0) cout << -1 << endl;
	else{
		for (i=0; i<blen; i++) cout << buff[i] << endl;
	}
	return 0;
}
