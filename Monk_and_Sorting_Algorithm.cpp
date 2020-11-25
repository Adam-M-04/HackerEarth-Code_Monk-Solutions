#include <bits/stdc++.h> 
#include <cstdio>

using namespace std;
long long int x = 1, maxLen=0;

void merge(long long int A[ ] , int start, int mid, int end, int chunks[]) {

	int p = start ,q = mid+1;
	long long int A2[end-start+1], chunks2[end-start+1], k=0;

	for(int i = start ;i <= end ;i++) {
    	if(p > mid){
       		A2[ k ] = A[ q] ;
			chunks2[ k++ ] = chunks[ q++] ;
		}else if ( q > end) {
       		A2[ k ] = A[ p ];
			chunks2[ k++ ] = chunks[ p++] ;
		}else if( chunks[p] <= chunks[q]){
      		A2[ k ] = A[ p ];
			chunks2[ k++ ] = chunks[ p++] ;
		}else{
      		A2[ k ] = A[ q];
			chunks2[ k++ ] = chunks[ q++] ;
		}
 	}
  	for (int i=0 ; i < k ; i++) {
    	A[ start ] = A2[ i ] ;
		chunks[ start++ ] = chunks2[ i ] ;
  	}
}

void merge_sort (long long int A[ ] , int start , int end, int chunks[] )
{
    if( start < end ) {
        int mid = (start + end ) / 2 ;         
        merge_sort (A, start , mid , chunks) ;               
        merge_sort (A,mid+1 , end , chunks) ;              
        merge(A,start , mid , end , chunks);   
    }                    
}

int main() {

	int n; scanf("%d", &n);
	long long int arr[n];
	int chunks[n];

	for(int i=0; i<n; i++){
		scanf("%lld", &arr[i]);
		if(arr[i] > maxLen) maxLen = arr[i];
	}
	while(x < maxLen){
		for(int i=0; i<n; i++){
			chunks[i] = arr[i] / x % 100000;
		}
		merge_sort(arr, 0, n-1, chunks);
		for(int i=0; i<n; i++){
			printf("%lld ", arr[i]);
		}
		printf("\n");
		x *= 100000;
	}
}
