#include <iostream>
#include<algorithm>
using namespace std;
int quicksort(int *list, int low, int high, int *list2);
void swap(int *list, int low, int high, int *list2);

int main()
{	int i, j, n, temp[2], ans=-1, start=0, min, tmp=0;
	bool judge = true, firstTime = true;

	cin >> n;
	int time1[n], time2[n];
	for (i=0; i<n; ++i) cin >> time1[i] >> time2[i];
	
	quicksort(time1,0,n-1,time2);
	
	while (judge){
		ans++;
		min = 1000000;
		judge = false;
		
		for (i=start; i<n; ++i){
			if (time2[i] < min && (time1[i] >= time2[start] || firstTime)){
				min = time2[i];
				tmp = i;
				judge = true;
			}
			if (time1[i] > min) break;
		}
		
		start = tmp;
		firstTime = false;
	} 
	
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
        while(list[++left] < pivot);         
        while(right != 0 && list[--right] > pivot);         
        swap(list, left, right, list2);     
    } while (left < right);          
    
    swap(list, left, right, list2);     
    swap(list, left, high, list2);          
    
    quicksort(list, low, left - 1, list2);     
    quicksort(list, left + 1, high, list2); 
}
