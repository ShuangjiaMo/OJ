#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{	string str;
	long long i, j, k, q, ans_1, ans_3=0, cnt_S=0, cnt_T=0, cnt_A=0, cnt_R=0;
	bool judge;
	
	cin >> str;
	
	for (i=0; i<str.length(); ++i){
		switch(str[i]){
			case 'S': cnt_S++; break;
			case 'T': cnt_T++; break;
			case 'A': cnt_A++; break;
			case 'R': cnt_R++; break;
			default: break;
		}
	}
	
	for (i=0; i<str.length(); ++i){
		judge = false;
		if (str[i] == 'S'){
			for (j=i+1; j<str.length(); ++j){
				if (str[j] == 'T'){
					for (k=j+1; k<str.length(); ++k){
						if (str[k] == 'A'){
							for (q=k+1; q<str.length(); ++q){
								if (str[q] == 'R'){
									++ans_3;
									str[i] = ' ';
									str[j] = ' ';
									str[k] = ' ';
									str[q] = ' ';
									judge = true;
									break;
								}
							}
						}
						if (judge) break;
					}
				}
				if (judge) break;
			}
		}
	}
	
	ans_1 = cnt_S * cnt_T * cnt_A * cnt_R;
	cout << ans_1 << ' ' << min(min(cnt_S,cnt_T), min(cnt_A,cnt_R)) << ' ' << ans_3;
	return 0;
}

