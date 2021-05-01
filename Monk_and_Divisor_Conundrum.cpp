#include <iostream>
using namespace std;

int main()
{
    int n, arr[200001], tmp, maks=0;
    cin >> n;

    for(int i=0; i<=200001; ++i) arr[i]=0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        maks = (tmp > maks) ? tmp : maks;
        arr[tmp]++;
    }

    int t, x,y;
    cin >> t;

    for(int i=0; i<t; ++i){
        int cnt=0;
        cin >> x >> y;
        for(int j=x; j<=maks; j+=x){
            cnt += arr[j];
        }
        for(int j=y; j<=maks; j+=y){
            if(j%x == 0) continue;
            cnt += arr[j];
        }
        cout << cnt << endl;
    }

    return 0;
}
