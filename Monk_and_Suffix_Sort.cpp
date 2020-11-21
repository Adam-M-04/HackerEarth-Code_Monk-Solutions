#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int q, n=s.length(); 
	cin >> q;
	string sorted[n];
	for(int i=0; i<n; i++){
		string suf = s.substr(i);
		int j=n-i-1;
		while(j < n-1 && suf > sorted[j+1]){
			sorted[j] = sorted[j+1];
			j++;
		}
		sorted[j] = suf;
	}
	cout << sorted[q-1];
}
