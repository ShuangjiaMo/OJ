#include <iostream>
#include <string>
using namespace std;

int main()
{	int q, i, j, k, x, round=1, *s, len;
	string str;
	bool find;
	
	while (cin >> q){
		cout << "Case #" << round << ":" << endl;
		
		s = new int[q];
		len = 0;
		
		for (i=0; i<q; i++){
			cin >> str >> x;
			switch(str[0]){
				case 'I':{
					find = false;
					for (j=0; j<len; j++){
						if (s[j] == x){
							find = true;
							break;
						}
					}
					if (not find) s[len++] = x;
					break;
				}
				case 'D':{
					for (j=0; j<len; j++){
						if (s[j] == x){
							for (k=j; k<len; k++) s[k] = s[k+1];
							len--;
							break;
						}
					}
					break;
				}
				case 'Q':{
					
					break;
				}
			}
		}
		
		delete [] s;
		round++;
	}
	
	return 0;
}
