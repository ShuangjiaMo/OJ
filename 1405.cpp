#include <iostream>
using namespace std;

int sum=0, n;
bool flag=false;

void quickSort(int s[], int l, int r)  {  
    if (l< r){        
        int i = l, j = r, x = s[l];  
        while (i < j){  
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

void find(int s[], int start, int total=0){
	if (total*2 > sum || start >= n) return;
	if (total*2 == sum){
		flag = true;
		return;
	}
	
	find(s, start+1, total+s[start]);
	find(s, start+1, total);
}

int main()
{	int num[505], i, j;
	
	cin >> n;
	for (i=0; i<n; i++){
		cin >> num[i];
		sum += num[i];
	}
	quickSort(num, 0, n-1);
	
	for (i=0; i<n; i++){
		find(num, i);
		if (flag){
			cout << sum/2;
			return 0;
		}
		sum -= num[i];
		while (sum%2 == 1) sum -= num[++i];
	}
	
	cout << "Impossible";
	return 0;
}
