#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	vector < long long int > distance;
	for(int j=0; j<t; j++){
		long long int n, k; cin >> n >> k;
		string s; cin >> s;
		string maks = "0";
		distance.clear();
		for(int i=0; i<n; i++){
			if(s > maks){
				distance = {i};
				maks = s;
			}else if(s == maks){
				distance.push_back(i);
			}
			s = s.substr(1) + s[0];
		}
		k--;
		long long int m = distance.size();
		long long int suma = k / m * n + distance[k % m];
		cout << suma << endl;
	}
}
