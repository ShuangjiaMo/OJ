#include <iostream>
#include <string>
using namespace std;

int main()
{	int i, j, t, judge;
	bool finish;
	string str[4];
	
	cin >> t;
	
	for (; t>0; t--){
		for (i=0; i<4; i++) cin >> str[i];
		finish = true;
		
		for (i=0; i<4; i++){
			for (j=0; j<4; j++){
				if (str[i][j] == '.') finish = false;
			}
		}
		
		judge = 0;
		for (i=0; i<4; i++){
			if ((str[i][0]=='X' || str[i][0]=='T') && (str[i][1]=='X' || str[i][1]=='T') && (str[i][2]=='X' || str[i][2]=='T') && (str[i][3]=='X' || str[i][3]=='T')){
				judge = 1;
				break;
			}
			if ((str[i][0]=='O' || str[i][0]=='T') && (str[i][1]=='O' || str[i][1]=='T') && (str[i][2]=='O' || str[i][2]=='T') && (str[i][3]=='O' || str[i][3]=='T')){
				judge = 2;
				break;
			}
		}
		if (judge == 1){
			cout << "X won" << endl;
			continue;
		}
		if (judge == 2){
			cout << "O won" << endl;
			continue;
		}
		
		judge = 0;
		for (j=0; j<4; j++){
			if ((str[0][j]=='X' || str[0][j]=='T') && (str[1][j]=='X' || str[1][j]=='T') && (str[2][j]=='X' || str[2][j]=='T') && (str[3][j]=='X' || str[3][j]=='T')){
				judge = 1;
				break;
			}
			if ((str[0][j]=='O' || str[0][j]=='T') && (str[1][j]=='O' || str[1][j]=='T') && (str[2][j]=='O' || str[2][j]=='T') && (str[3][j]=='O' || str[3][j]=='T')){
				judge = 2;
				break;
			}
		}
		if (judge == 1){
			cout << "X won" << endl;
			continue;
		}
		if (judge == 2){ 
			cout << "O won" << endl;
			continue;
		}
		
		judge = 0;
		if ((str[0][0]=='X' || str[0][0]=='T') && (str[1][1]=='X' || str[1][1]=='T') && (str[2][2]=='X' || str[2][2]=='T') && (str[3][3]=='X' || str[3][3]=='T')){
			judge = 1;
		}
		if ((str[3][0]=='X' || str[3][0]=='T') && (str[2][1]=='X' || str[2][1]=='T') && (str[1][2]=='X' || str[1][2]=='T') && (str[0][3]=='X' || str[0][3]=='T')){
			judge = 1;
		}
		if ((str[0][0]=='O' || str[0][0]=='T') && (str[1][1]=='O' || str[1][1]=='T') && (str[2][2]=='O' || str[2][2]=='T') && (str[3][3]=='O' || str[3][3]=='T')){
			judge = 2;
		}
		if ((str[3][0]=='O' || str[3][0]=='T') && (str[2][1]=='O' || str[2][1]=='T') && (str[1][2]=='O' || str[1][2]=='T') && (str[0][3]=='O' || str[0][3]=='T')){
			judge = 2;
		}
		if (judge == 1){
			cout << "X won" << endl;
			continue;
		}
		if (judge == 2){
			cout << "O won" << endl;
			continue;
		}
		
		if (finish) cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;
	}
	
	return 0;
}
