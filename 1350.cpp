#include <iostream>  
#include <stdio.h>
#include <stdlib.h> 
#include <memory.h>  
using namespace std;  
  
const double INF=210000000;  
  
struct point  
{  
    int x,y;  
};  
int cmp(const void *a ,const void *b)  
{  
    if( *(double*)a> *(double *)b)  
        return 1;  
    else  
        return -1;  
}  
point p[700];  
double k[700];  
  
int main()  
{  
//  freopen("in.txt","r",stdin);  
//  freopen("out.txt","w",stdout);  
  
    int N, i, j, l, counter, ans;  
    cin >> N;
    for(i=0;i<N;i++)                              
        cin >> p[i].x >> p[i].y ;  
    ans = 0;  
    for(i=0;i<N-1;i++){  
        for(j=i+1,l=0;j<N;j++,l++){  
            if(p[i].x==p[j].x) k[l]=INF;  
            else k[l]=double(p[i].y-p[j].y)/(p[i].x-p[j].x);  
        }  
        qsort(k,l,sizeof(k[0]),cmp);  
        for(j=0;j<l;j++){  
            counter=1;  
            while(j+1<l && k[j]==k[j+1]){  
                j++;  
                counter++;  
            }  
            if(counter>ans) ans=counter;  
        }  
    }  
	cout << ans+1; 
    return 0 ;  
}
