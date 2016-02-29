#include <iostream>
using namespace std;
 
int main()
{	int N, i, j, k, count=0, mot, son, temp[2], len;
	
	cin >> N;
	len = N*(N+1)/2;
	int ans[len][2];
	
	for (i=1; i<=N; ++i){
		for (j=1; j<=i; ++j){
			k=2;
			mot = i;
			son = j;
			while (k<=son){
				if (mot%k == 0 && son%k == 0){
					mot /= k;
					son /= k;
				}
				if (mot%k != 0 || son%k != 0) ++k;
			}
			
			ans[count][0] = son;
			ans[count][1] = mot;
			++count;
		}
	}
	
	for(i=0; i<len; i++){    
		for(j=0; j<len-i-1; j++){  
            if(double(ans[j][0])/ans[j][1] > double(ans[j+1][0])/ans[j+1][1]){  
                temp[0] = ans[j][0];
				temp[1] = ans[j][1];  
                ans[j][0] = ans[j+1][0];
				ans[j][1] = ans[j+1][1];  
                ans[j+1][0] = temp[0];  
                ans[j+1][1] = temp[1]; 
            }  
        } 
	}
	
	cout << 0 << '/' << 1 << endl;;
	temp[0] = -1;
	temp[1] = -1;
	for (i=0; i<len; ++i){
		if (ans[i][0] != temp[0] || ans[i][1] != temp[1]){
			cout << ans[i][0] << '/' << ans[i][1] << endl;
			temp[0] = ans[i][0];
			temp[1] = ans[i][1];
		}
	}
	return 0;
}
