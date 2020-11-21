#include <iostream>

using namespace std;

void getVal(int t[], int n){
	for(int i=0; i<n; i++){
		cin >> t[i];
	}
}

int maksimum(int t[], int n){
	int maks=t[0];
	for(int i=1; i<n; i++) maks = max(maks, t[i]);
	return maks;
}

void countSort(int t[], int n, int cnt[]){
	for(int i=0; i<n; i++){
		cnt[t[i]]++;
	}
}

void zeruj(int t[], int n){
	for(int i=0; i<n; i++){
		t[i] = 0;
	}
}

int main() {
	int x, n; cin >> x;
	for(int i=0; i<x; i++){
		cin >> n;
		int t[n];
		getVal(t, n); //Takes values from input to 't' array
		int mx = maksimum(t, n)+1; // mx - maximum element of 't' array
		int cnt[mx]; 
		zeruj(cnt, mx);	// set all values in 'cnt' array to 0
		countSort(t, n, cnt);
		int maxVal = 0, maxDiff = 0;
		for(int i=mx-1; i>=0; i--){
			if(cnt[i] != 0){
				if(i > 0 && cnt[i] > maxVal) maxVal = cnt[i];
				maxDiff = max(maxDiff, maxVal - cnt[i]);
			}
		}
		if(maxDiff > 0) cout << maxDiff << endl;
		else cout << -1 << endl;
	}
}
