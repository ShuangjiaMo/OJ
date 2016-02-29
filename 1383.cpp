#include <iostream>
#include <cstdio>  
#include <cstring>  
using namespace std;

int w, h;
long long dp[1<<11][11];
bool kexing[1<<11];
int full;
 
inline bool check(int in)
{	int bit=0;
    while(in>0){
            if( (in&1)==1) bit++;
            else{
                if( (bit&1)==1) return false;
                bit=0;
            }
            in>>=1;
    }

    if( (bit&1)==1) return false;
	return true;
}
 
inline bool check2(int x1,int x2){
    if ( (x1|x2)!= full-1 ) return false;
	return kexing[x1&x2];
}

int main()
{	full = 1<<11;
    for(int s = 0; s < full; ++s)if(check(s))kexing[s] = 1;
	
	while (true){
		cin >> w >> h;
		if (w==0 && h==0) break;
		
		memset(dp,0,sizeof(dp));
        full = 1<<h;
 
        for(int s = 0; s < full; ++s){
            if(kexing[s]) dp[s][0] = 1;
        }
 
        for(int i = 1; i < w; ++i){
            for(int s = 0; s < full; ++s){
                for(int s1 = 0; s1 < full; ++s1){
                    if(!check2(s1,s))continue;
                    dp[s][i] += dp[s1][i-1];
                }
            }
        }

        int S = (1<<h) - 1;
        cout << dp[S][w-1] << endl;
    }
	
	return 0;
}

 
