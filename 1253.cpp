#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int x;
    int y;
    int val;
    bool operator <(const node& a) const {
    	return val>a.val;  
    } 
};

int n, m, k, cur;
node a[25*25];

int main()
{	int ita, i, j, ans=0, cou=0;
	cin >> n >> m >> k;
	
	cur=0;
	for(i=0; i<n; i++){
	    for(j=0; j<m; j++){
			cin >> ita;
			if(ita){
			    a[cur].x=i+1;
			    a[cur].y=j+1;
			    a[cur++].val=ita;
			}
	    }		
	}
	sort(a,a+cur);
	
	if(k < a[0].x*2+1){
	    cout << 0;
	    return 0;
	}
	
	ans += a[cou].val;
	k -= a[cou++].x + 1;
	while(k>0 && cou<cur){
	    if(k < abs(a[cou].x-a[cou-1].x) + abs(a[cou].y-a[cou-1].y) + 1 + a[cou].x) break;
	    ans += a[cou].val;
	    k -= abs(a[cou].x-a[cou-1].x) + abs(a[cou].y-a[cou-1].y) + 1;
	    cou++;
	}
	
	cout << ans;
    return 0;
}

