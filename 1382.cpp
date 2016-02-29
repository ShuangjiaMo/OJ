#include <iostream>
using namespace std;

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

int main()
{	long long n, s, i, j, ans=0, start;
	
	cin >> n >> s;
	int l[n];
	for (i=0; i<n; ++i) cin >> l[i];
	
	quickSort(l,0,n-1);
	
	start = n-1;
	for (i=0; i<n; ++i){
		for (j=start; j>i; --j){
			if (l[i]+l[j] <= s){
				ans += j-i;
				start = j;
				break;
			}
		}
		if (j==i+1 && l[i]+l[j]>s) break;
	}
	
	cout << ans;
	return 0;
}
