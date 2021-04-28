#include <iostream>
#include <cmath>
using namespace std;

int check(long long int n, long long int m){
    if(n > m) return -1;
    for(long long int i=0; i<m; ++i){
        long long int power = pow(i,2);
        if(power % m == n) return i;
    }
    return -1;
}

int main() {

    long long int t,n,m;
    cin >> t;

    for(int x=0; x<t; ++x){
        cin >> n >> m;
        cout << check(n, m) << endl;
    }

}
