#include <iostream>
using namespace std; 

int m, n, m1, m2, ans=1000000;

void jump(int nb[35][35], int x, int y, int c)
{	if (x<0 || x>=m || y<0 || y>=n) return;
	if (nb[x][y] == 4){
		if (ans > c) ans = c;
		return;
	}
	
	if (nb[x][y] == 1 || nb[x][y] == 3){
		nb[x][y] = 0;
		jump(nb, x+m1, y+m2, c+1);
		jump(nb, x+m2, y+m1, c+1);
		jump(nb, x-m1, y+m2, c+1);
		jump(nb, x+m1, y-m2, c+1);
		jump(nb, x-m1, y-m2, c+1);
		jump(nb, x-m2, y+m1, c+1);
		jump(nb, x+m2, y-m1, c+1);
		jump(nb, x-m2, y-m1, c+1);
	}
}

int main()
{	int i, j, x0, y0;

	cin >> m >> n >> m1 >> m2;
	int num[35][35];

	for (i=0; i<m; ++i){
		for (j=0; j<n; ++j){
			cin >> num[i][j];
			if (num[i][j] == 3){
				x0 = i;
				y0 = j;
			}
		}
	}
	
	jump(num, x0, y0, 0);
	
	cout << ans;
	return 0;
} 
