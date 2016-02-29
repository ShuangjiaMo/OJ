#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int father[200000+5] = {0}; 
bool alive[200000+5] = {false}; 
int sons[200000+5]={0};

int main()
{	int N, cnt=1;
	cin>>N;

    for (int i = 0; i < N; ++i){
        char op;
        op = getchar();
        while(op!='B' and op!='D'){
            op = getchar();
        }
        while (op != 'B' &&  op != 'D') 
            scanf("%c",&op);
        int x , y;
        switch(op){
            case 'B':{
            	scanf("%d %d",&x,&y);
                if(!alive[x]) sons[x] = 0;
                father[y] = x;
                alive[x] = alive[y] = true; 
                sons[x]++;
				break;
			}
            case 'D':{
            	scanf("%d",&x);
                alive[x] = false;
                if(!alive[father[x]]) cnt--;
                else
                    sons[father[x]]--;
                cnt += sons[x];
                   printf("%d\n", cnt);
				break;
			}
        }
    }
    
	return 0;
}
 
