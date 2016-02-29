#include <iostream>
#include <cstdio>
using namespace std;
void quickSort(int a[],int,int); 

int main()
{	int n, m, i, j, result;
	scanf("%d%d", &n, &m);
	
	int score[n], intv[m][2];
	for (i=0; i<n; ++i) scanf("%d", &score[i]);
	for (i=0; i<m; ++i) scanf("%d%d", &intv[i][0], &intv[i][1]);
	quickSort(score,0,n-1);
	
	for (i=0; i<m; ++i){
		result = 0;
		
		for (j=n/2; j<n; ++j){
			if (intv[i][1] < score[j] && intv[i][0] > score[n-j-1]) break;
			if (intv[i][0] <= score[j] && intv[i][1] >= score[j]) ++result;
			if (intv[i][0] <= score[n-j-1] && intv[i][1] >= score[n-j-1]) ++result;
		}
		
		printf("%d\n", result);
	}
	
	return 0;
}

void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) 
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) 
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); 
        quickSort(s, i + 1, r);  
    }  
}  
