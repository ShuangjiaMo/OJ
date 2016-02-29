#include<iostream>
using namespace std;

void quickSort(long long s[], long long l, long long r)
{
	if (l< r)
	{      
		long long i = l, j = r, x = s[l];
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
{
    long long n, a[10005], i, j, k, ans=0, tmp;
    bool find;
	cin >> n;
	for (i=0; i<n; i++) cin >> a[i];
	
	quickSort(a, 0, n-1);
	for (i=1; i<n; i++){
		tmp = a[i-1] + a[i]; 
		ans += tmp;
		find = false;
		
		for (j=i+1; j<n; j++){
			if (tmp <= a[j]){
				for (k=i; k<j-1; k++) a[k] = a[k+1];
				a[j-1] = tmp;
				find = true;
				break;
			}
		}
		if (not find){
			for (k=i; k<n; k++) a[k] = a[k+1];
			a[n-1] = tmp;
		}
	}
    
    cout << ans;
    return 0;
}
