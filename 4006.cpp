#include <iostream>
#include<algorithm>
using namespace std;
int quicksort(int *list, int low, int high, int *list2);
void swap(int *list, int low, int high, int *list2);

int main()
{	int n, i, j, count, time=1, ans=0, b;
	
	cin >> n;
	int t[n], a[n], num[n];
	for (i=0; i<n; ++i){
		cin >> t[i];
		num[i] = 0;
	}
	for (i=0; i<n; ++i) cin >> a[i];
	
	quicksort(a,0,n-1,t);	
	
	for (i=0; i<n; ++i){
		count = 1;
		while (a[i+count] == a[i]) ++count;
		sort(t, t+count, greater<int>());
		
		for (j=i; j<i+count; ++j){
			b = 1;
			while (num[t[j]-b] != 0){
				++b;
				if (t[j]-b < 0) break;
			}
			
			if (t[j]-b >= 0) num[t[j]-b] = a[j];
		}
		
		i += count-1;
	}
	
	for (i=0; i<n; ++i) ans += num[i];
	cout << ans;
	return 0;
}

void swap(int *list, int low, int high, int *list2)
{    
    int temp = list[low], temp2 = list2[low];
    list[low] = list[high];
    list2[low] = list2[high];
    list[high] = temp;
    list2[high] = temp2;
}

int quicksort(int *list, int low, int high, int *list2)
{
    int pivot = list[ (low + high) / 2 ];
    int left = low - 1;
    int right = high;
    
    if(low >= high) 
        return 0;
    
    swap(list, (low + high) / 2, high, list2);          
    do     
    {
        while(list[++left] > pivot);         
        while(right != 0 && list[--right] < pivot);         
        swap(list, left, right, list2);     
    } while (left < right);          
    
    swap(list, left, right, list2);     
    swap(list, left, high, list2);          
    
    quicksort(list, low, left - 1, list2);     
    quicksort(list, left + 1, high, list2); 
}
