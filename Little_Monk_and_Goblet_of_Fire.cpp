#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	queue<int> sql1, sql2,sql3,sql4, order;
	char query;
	int sql, num;
	
	for(int i=0; i<q; i++){
		char query;
		scanf(" %c", &query);
		if(query == 'D'){
			switch(order.front()){
				case 1:
					printf("%d %d\n", 1, sql1.front());
					sql1.pop();
					if(sql1.size() == 0) {order.pop();}
					break;
				case 2:
					printf("%d %d\n", 2, sql2.front());
					sql2.pop();
					if(sql2.size() == 0) {order.pop();}
					break;
				case 3:
					printf("%d %d\n", 3, sql3.front());
					sql3.pop();
					if(sql3.size() == 0) {order.pop();}
					break;
				case 4:
					printf("%d %d\n", 4, sql4.front());
					sql4.pop();
					if(sql4.size() == 0) {order.pop();}
					break;
			}
		}else {
			scanf("%d %d", &sql, &num);
			switch(sql){
				case 1:
					if(sql1.size() == 0) order.push(1);
					sql1.push(num);
					break;
				case 2:
					if(sql2.size() == 0) order.push(2);
					sql2.push(num);
					break;
				case 3:
					if(sql3.size() == 0) order.push(3);
					sql3.push(num);
					break;
				case 4:
					if(sql4.size() == 0) order.push(4);
					sql4.push(num);
					break;
			}
		}
	}
}
