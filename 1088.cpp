#include <vector>
#include <iostream>
using namespace std;

int map[16][16]={0};
int n=0;

const int INF=768000;
int f[1<<16][16]={0};
void initialize(){
    cin>>n;
    for (int i = 0; i < n; ++i){
        for (int j=0; j < n; ++j){
            cin>>map[i][j];
        }
    }
} 

int build(){
    for (int i = 0; i < ( 1 << (n-1) ); ++i)
    {
        for (int j = 1; j < n ; ++j){
            if(i == ( 1 << (j-1) ))
                f[i][j] = map[0][j];
            else{
                if(i & (1 << (j-1) ))
                {
                    f[i][j] = INF;
                    for( int k = 1; k < n ;  ++k)
                        if(k!=j and (i & ( 1<< (k-1) ) ) )
                            f[i][j] = min(f[i^(1<<(j-1))][k] + map[k][j], f[i][j]);

                }
            }
        }
    }
 
    int res = INF;
    for (int i = 1; i < n; ++i)
    {
        res = min(res, f[(1<<(n-1))-1][i] + map[i][0]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    initialize();
    if(n==1)
        cout<<2*map[0][0]<<endl;
    else
        cout<<build()<<endl;
    return 0;
}
