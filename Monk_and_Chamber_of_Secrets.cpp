#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	queue<int> q, indexes, rotation;
	for(int i=0; i<n; i++){
		int tmp; scanf("%d", &tmp);
		q.push(tmp);
		indexes.push(i+1);
	}
	int maks = -1;
	for(int i=0; i<x; i++){
		for(int j=0; j<x && !q.empty(); j++){
			if(q.front() > maks) maks = q.front();
			rotation.push(q.front());
			q.pop();
		}
		while(!rotation.empty()){
			if(rotation.front() == maks){
				printf("%d ", indexes.front());
				rotation.pop();
				indexes.pop();
				maks = -1;
				continue;
			}
			indexes.push(indexes.front());
			indexes.pop();
			q.push(rotation.front() == 0 ? 0 : rotation.front() -1);
			rotation.pop();
		}
	}
}
