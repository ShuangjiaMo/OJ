#include <iostream>
using namespace std;

int screen[20][20];
int h, w, ans=1000000;

void judge(int count)
{	int tmp[h][w];
	for (int i=0; i<h; ++i){
		for (int j=0; j<w; ++j){
			tmp[i][j] = screen[i][j];
		}
	}
	
	if (h==1){
		for (int j=0; j<w; j++){
			if (tmp[0][j]%2 != 0) return;
		}
		if (count < ans) ans = count;
		return;
	}
	else{
		for (int i=1; i<h; i++){
			for (int j=0; j<w; j++){
				if (tmp[i-1][j]%2 != 0){
					count++;
					tmp[i-1][j]++;
					tmp[i][j]++;
					if (i!=h-1) tmp[i+1][j]++;
					if (j==0) tmp[i][j+1]++;
					else if (j==w-1) tmp[i][j-1]++;
					else{
						tmp[i][j+1]++;
						tmp[i][j-1]++;
					}

				}
			}
			
			if (i==h-1){
				for (int j=0; j<w; j++){
					if (tmp[i][j]%2 != 0) return;
				}
				if (count < ans) ans = count;
				return;
			}
		}
	}

}

void set(int n, int count)
{	if (n==0){
		set(n+1, count);
		screen[0][n]++;
		screen[0][n+1]++;
		if (h>1) screen[1][n]++;
		set(n+1, count+1);
		screen[0][n]--;
		screen[0][n+1]--;
		if (h>1) screen[1][n]--;
	}
	else if (n==w-1){
		judge(count);
		screen[0][n-1]++;
		screen[0][n]++;
		if (h>1) screen[1][n]++;
		judge(count+1);
		screen[0][n-1]--;
		screen[0][n]--;
		if (h>1) screen[1][n]--;
	} 
	else{
		set(n+1, count);
		screen[0][n-1]++;
		screen[0][n]++;
		screen[0][n+1]++;
		if (h>1) screen[1][n]++;
		set(n+1, count+1);
		screen[0][n-1]--;
		screen[0][n]--;
		screen[0][n+1]--;
		if (h>1) screen[1][n]--;		
	}
}

int main()
{	int i, j;
	
	cin >> h >> w;
	for (i=0; i<h; ++i){
		for (j=0; j<w; ++j){
			cin >> screen[i][j];
		}
	}
	
	set(0, 0);
	
	if (ans==1000000) cout << -1;
	else cout << ans;
	return 0;
}
