#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0 ;

struct point
{
    int x,y;
};

point epts[81+5];

bool r[10][10], c[10][10], sq[4][4][10];

int G[10][10];

int ans = 0;

void dfs(int cur){
    if(ans > 1)
        return;
    if(cur < 0) {
        bool ok = true;
        for (int i = 0; i < 9; ++i){
            for (int j=1; j <= 9; ++j){
                if( (!r[i][j]) || (!c[i][j]) || (!sq[i/3][i/3][j]))
                    ok = false;
            }
        }
        if(ok)
            ans++;
        return;
    }
    int x = epts[cur].x;
    int y = epts[cur].y;
    
    for (int k = 1; k <= 9; ++k)
    {
        if(r[x][k] || c[y][k] || sq[x/3][y/3][k])
            continue;
        r[x][k] = c[y][k] = sq[x/3][y/3][k] = true;
        dfs(cur-1);
        r[x][k] = c[y][k] = sq[x/3][y/3][k] = false;
    }
    
    return;
}


int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    for (int t = 0; t < T; ++t)
    {
        cnt = 0;//³õÊ¼»¯
        ans = 0;
        memset(r,false,sizeof(r));
        memset(c,false,sizeof(c));
        memset(sq,false,sizeof(sq));
        
        for (int i = 0; i < 9; ++i){
            for (int j=0; j < 9; ++j){
                int k;
                cin>>k;
                G[i][j] = k;
                if(k>0)
                    r[i][k] = c[j][k] = sq[i/3][j/3][k] = true;
                else
                    epts[cnt++] = (point){i,j}; 
            }
        }
        
        dfs(cnt-1);
        
        if(ans==1){ 
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
