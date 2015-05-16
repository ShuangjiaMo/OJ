#include <iostream>
using namespace std;
 
int main()
{	int L, W, area_L, area_W, i, j, total, max = 0, x = 0, y = 0;
	
	cin >> L >> W;
	int garden[L][W];
	
	for (i=0; i<L; ++i) for (j=0; j<W; ++j) cin >> garden[i][j];
	cin >> area_L >> area_W;
	
	do{	total = 0;
 
		for (i=y; i<y+area_L; ++i) for (j=x; j<x+area_W; ++j) total += garden[i][j];
		if (total > max) max = total;
		
		if (area_L < area_W){
			while (x+area_W < W){
				++x;
				for (i=y; i<y+area_L; ++i) total = total - garden[i][x-1] + garden[i][x+area_W-1];
				if (total > max) max = total;
			}
			
			if (x+area_W == W && y+area_L < L){
				x = 0;
				++y;
			}
			else {
				if (y+area_L == L && x+area_W == W) break;	
			}
		}
		else{
			while (y+area_L < L){
				++y;
				for (j=x; j<x+area_W; ++j) total = total - garden[y-1][j] + garden[y+area_L-1][j];
				if (total > max) max = total;
			}
			
			if (y+area_L == L && x+area_W < W){
				y = 0;
				++x;
			}
			else {
				if (x+area_W == W && y+area_L == L) break;	
			}
		}
	} while (y+area_L <= L || x+area_W <= W);
	
	cout << max;
	return 0;
}
