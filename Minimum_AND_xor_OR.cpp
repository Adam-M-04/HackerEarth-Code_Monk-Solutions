#include <stdio.h>
#include <iostream>

using namespace std;

void countsort(int arr[],int n,int place)
{
    int i,freq[10]={0};
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

void radixsort(int arr[],int n, int maxx)           
{
        int mul=1;
        while(maxx)
        {
            countsort(arr,n,mul);
            mul*=10;
            maxx/=10;
        }
}

int minXOR(int arr[], int n, int maks) 
{ 
    radixsort(arr, n, maks); 
  
    int minXor = arr[0] ^ arr[1]; 
    int val = 0; 
  
    for (int i = 0; i < n - 1; i++) { 
        val = arr[i] ^ arr[i + 1]; 
        minXor = min(minXor, val); 
    } 
  
    return minXor; 
} 

int main() {
	int t, n;
	scanf("%d", &t);
	for(int q=0; q<t; q++){
		scanf("%d", &n);
		int arr[n], maks = 0;
		for(int i=0; i<n; i++){ 
			scanf("%d", &arr[i]);
			maks = max(maks, arr[i]);
		}
		printf("%d\n", minXOR(arr, n, maks));
	}
}
