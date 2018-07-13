#include <stdio.h>

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int a[n];
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for(int j = 1; j < n; j++){
			int key = a[j];
			//Insert A[j] into the sorted sequence A[1..j-1]. 
			int i = j - 1;
			while(i >= 0 && a[i] > key){
				a[i + 1] = a[i];
				i = i - 1;
			}
			a[i + 1] = key;
		} 
		for(int i = 0; i < n; i++){
			printf("%d", a[i]);
		}
	}
} 
