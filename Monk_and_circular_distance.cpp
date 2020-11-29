#include <stdio.h>
#include <cmath>
using namespace std;

void merge(double A[ ] , int start, int mid, int end) {
    int p = start ,q = mid+1, k=0;
    double Arr[end-start+1];

    for(int i = start ;i <= end ;i++) {
        if(p > mid)      
            Arr[ k++ ] = A[ q++] ;
        else if ( q > end)   
            Arr[ k++ ] = A[ p++ ];
        else if( A[ p ] < A[ q ])   
            Arr[ k++ ] = A[ p++ ];
        else
            Arr[ k++ ] = A[ q++];
    }
    for (int p=0 ; p< k ;p ++) {
        A[ start++ ] = Arr[ p ] ;                          
    }
}

void merge_sort (double A[ ] , int start , int end )
{
    if( start < end ) {
        int mid = (start + end ) / 2 ;   
        merge_sort (A, start , mid ) ;     
        merge_sort (A, mid+1 , end ) ;      
        merge(A,start , mid , end );   
    }                    
}

int binarySearch(double t[], int l, int r, double q){
    while(l <= r){
        int mid = (l + r) / 2;
        if(t[mid] > q){
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
	int n;
    scanf("%d", &n); 
    double diameters[n], x, y;
    for(int i=0; i<n; i++){
        scanf("%lf %lf", &x, &y);
        diameters[i] = sqrt(x*x + y*y);
    }
    merge_sort(diameters, 0, n-1);

    int q; scanf("%d", &q);
    double query;
    for(int i=0; i<q; i++){
        scanf("%lf", &query);
        printf("%d\n", binarySearch(diameters, 0, n-1, query));
    }
}
