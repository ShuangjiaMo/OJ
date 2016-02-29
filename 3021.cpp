#include <iostream>  
using namespace std;
long long ans=0;  

void merge(int *data, int start, int mid, int last)  
{   int n1, n2, i, j, k=start;  
   
    n1 = mid-start+1;   
    n2 = last-mid;  
   
    int left[n1], right[n2];   
    for(i=0; i<n1; i++) left[i] = data[start+i];  
    for(j=0; j<n2; j++) right[j] = data[mid+1+j];  
   
    i = j = 0;    
    while(i<n1 && j<n2) {  
        if(left[i] <= right[j]) data[k++] = left[i++];  
        else{
        	data[k++] = right[j++];
        	ans += n1-i;
		}  
    }  
   
    for(; i<n1; i++) data[k++] = left[i];  
    for(; j<n2; j++) data[k++] = right[j];  
}  
   
void mergeSort(int *data, int start, int last)  
{   int mid;  
    
	if(start < last) {  
        mid = (start + last) / 2;   
        mergeSort(data, start, mid);   
        mergeSort(data, mid+1, last); 
        merge(data, start, mid, last);   
    }  
}  

int main()
{	int n, i;
	
	cin >> n;
	int num[n];
	for (i=0; i<n; ++i) cin >> num[i];
	
	mergeSort(num,0,n-1);
	
	cout << ans;
	return 0;
} 

