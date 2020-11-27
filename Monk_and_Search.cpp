#include <iostream>

using namespace std;

void countsort(int arr[],int n,int place)
{
    int i, freq[10]={0};       
    int output[n];
    for(i=0;i<n;i++)
        freq[(arr[i]/place)%10]++;
    for(i=1;i<10;i++)
        freq[i]+=freq[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[freq[(arr[i]/place)%10]-1]=arr[i];
        freq[(arr[i]/place)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i]=output[i];
}
void radixsort(int arr[],int n,int maxx)           
{
    int mul=1;
    while(maxx)
    {
        countsort(arr,n,mul);
        mul*=10;
        maxx/=10;
    }
}

int binarySearch(int t[], int l, int r, int query){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(t[mid]<query)
     	{
         	l=mid+1;
     	}
     	else if(t[mid]>query)
     	{
        	r=mid-1;
     	}
     	else
     	{
         	break;
     	}
	}
	return mid;
}

int main() {
	int n; scanf("%d", &n);
	int arr[n], maks=0;
	for(int i=0; i<n; i++){ 
		scanf("%d", &arr[i]);
		if(arr[i] > maks) maks = arr[i];
	}
	radixsort(arr, n, maks);
	int t; scanf("%d", &t);
	for(int i=0; i<t; i++){
		int q,x; scanf("%d %d", &q, &x);
		int index = binarySearch(arr, 0, n-1, x);
		if(q == 0){
			while(index >= 0 && arr[index] >= x) index--;
			while(index < n && arr[index] < x) index++;
		}else {
			while(index >= 0 && arr[index] > x) index--;
			while(index < n && arr[index] <= x) index++;
		}
		printf("%d\n", n-index);
	}
}
