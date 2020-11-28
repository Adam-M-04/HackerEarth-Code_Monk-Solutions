#include <iostream>

using namespace std;

int main() {
	int n;
	long long x, suma=0;
	scanf("%d %lld", &n, &x);
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	int maxLen = 0;
	int i=0, j=0;

	while(suma + arr[j] <= x && j<n){
		suma += arr[j++];
		maxLen++;
	}
	while(j < n && maxLen){
		while(suma <= x && j<n && maxLen){
			suma -= arr[i++];
			suma += arr[j++];
		}
		while(suma > x && maxLen){
			suma -= arr[i++];
			maxLen--;
		}
	}
	printf("%d", maxLen);
}
