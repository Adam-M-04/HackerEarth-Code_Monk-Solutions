#include <stdio.h>

using namespace std;

int main() {
	int n,m,g;
	scanf("%d %d %d", &n, &m, &g);
	int rain[n], clothes[m];
	for(int i=0; i<n; i++) scanf("%d", &rain[i]);
	for(int i=0; i<m; i++) scanf("%d", &clothes[i]);
	
	int maxDif=0, cnt = 0;

	for(int i=0; i<n-1; i++)
		if(maxDif < rain[i+1] - rain[i])
			maxDif = rain[i+1] - rain[i];

	for(int i=0; i<m; i++){
		if(maxDif >= clothes[i]) cnt++;
	}
	printf("%d", cnt);
}
