#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int n, cnt=0; cin >> n;
		int arr[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> arr[i][j];
			}
		}
		for(int a=0; a<n; a++){
			for(int b=0; b<n; b++){
				for(int c=a; c<n; c++){
					for(int d=b; d<n; d++){
						if(arr[a][b] > arr[c][d]) cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
}
