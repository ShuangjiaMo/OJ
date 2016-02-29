#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{	int n, m, num[10005][3], opt[3], i, j;
	bool find;
	
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d%d%d", &num[i][0], &num[i][1], &num[i][2]);
	scanf("%d", &m);
	
	for (j=0; j<m; j++){
		scanf("%d%d%d", &opt[0], &opt[1], &opt[2]);
		
		switch(opt[0]){
			case 0:{
				for (i=0; i<n; i++){
					if (num[i][0] == opt[1]) num[i][0] = opt[2];
					else if (num[i][0] == opt[2]) num[i][0] = opt[1];
				}
				break;
			}
			case 1:{
				for (i=0; i<n; i++){
					if (num[i][1] == opt[1]) num[i][1] = opt[2];
					else if (num[i][1] == opt[2]) num[i][1] = opt[1];
				}
				break;
			}
			case 2:{
				find = false;
				for (i=0; i<n; i++){
					if (num[i][0]==opt[1] && num[i][1]==opt[2]){
						printf("%d\n", num[i][2]);
						find = true;
						break;
					}
				}
				if (not find) printf("%d\n",0);
				break;
			}
		}
	}
	
	return 0;
} 
