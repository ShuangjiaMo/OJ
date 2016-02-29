#include<iostream>
#include<algorithm>
using namespace std;

int d[2005][2005],x[256],i,j,p,n,m;

int main()
{	char s[2005],c;
	
	cin >> n >> m >> s+1;
	for(i=1;i<=n;i++){
		cin >> c >> j >> p;
		x[c]=min(j,p);
	}
	
	for(p=1;p<m;p++){
		for(i=1;i+p<=m;i++){
			d[i][j=i+p]=-1u>>1;
			d[i][j]=min(d[i+1][j]+x[s[i]],d[i][j-1]+x[s[j]]);
			if(s[i]==s[j])
				d[i][j]=min(d[i][j],d[i+1][j-1]);
		}
	}
	
	cout << d[1][m];
	return 0;
}

