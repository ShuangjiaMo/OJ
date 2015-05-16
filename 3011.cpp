#include <iostream>
using namespace std;
 
int main()
{	int n, i, j, temp[2], work, rest, max_work, max_rest, start=0;
	
	cin >> n;
	int time[n][2];
	
	for (i=0; i<n; ++i) cin >> time[i][0] >> time[i][1];
	
	for (i=1; i<n; ++i){	
		for (j=0; j<i; ++j){
			if (time[i][0] >= time[j][0] && time[i][0] <= time[j][1] && time[i][1] > time[j][1]){
				time[i][0] = time[j][1];
				continue;
			}
			if (time[i][1] >= time[j][0] && time[i][1] <= time[j][1] && time[i][0] < time[j][0]){
				time[i][1] = time[j][0];
				continue;
			}
			if (time[i][0] >= time[j][0] && time[i][0] <= time[j][1] && time[i][1] >= time[j][0] && time[i][1] <= time[j][1]){
				time[i][0] = -1;
				time[i][1] = -1;
				continue;
			}
			if (time[i][0] < time[j][0] && time[i][1] > time[j][1]){
				time[j][0] = -1;
				time[j][1] = -1;
				continue;
			}
		}
	}
	
	for(i=0; i<n; i++){    
		for(j=0; j<n-i-1; j++){  
            if((time[j][0] > time[j+1][0]) || ((time[j][0] == time[j+1][0]) && (time[j][1] > time[j+1][1]))){  
                temp[0] = time[j][0];
				temp[1] = time[j][1];  
                time[j][0] = time[j+1][0];
				time[j][1] = time[j+1][1];  
                time[j+1][0] = temp[0];  
                time[j+1][1] = temp[1]; 
            }  
        } 
	} 
	
	while(time[start][0] == -1) start++;
	work = time[start][1] - time[start][0];
	max_work = 0;
	max_rest = 0;
	for (i=start+1; i<n; ++i){
		if (time[i][0] == time[i-1][1]){
			work += time[i][1] - time[i][0];
		}
		else{
			rest = time[i][0] - time[i-1][1];
			if (rest > max_rest) max_rest = rest;
			if (work > max_work) max_work = work;
			work = time[i][1] - time[i][0];
		}
	}
	if (work > max_work) max_work = work;
	
	cout << max_work << ' ' << max_rest;
	return 0;
}
