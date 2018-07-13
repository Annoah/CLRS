#include <stdio.h>

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int a[n], v, j;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		printf("input v:");
		scanf("%d", &v);
		for(int i = 0; i < n; i++){
			if(a[i] == v){
				printf("%d",i + 1);
				printf(" ");
				j = 1;
			} 
		}
		if(j != 1){
			printf("NIL");
		}
	}
}
