#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	string arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<n; i++){
		int cnt=0;
		for(int j=i-1; j>=0; j--){
			if(arr[j]<arr[i]) cnt++;
		}
		cout << cnt << endl;
	}
}
