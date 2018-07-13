#include <stdio.h>
#include <algorithm>

void Binary_Search(int A[], int p, int r, int v){
	if(p < r){
		int q;
		q = (p + r) / 2;
		if(v < A[q]){
			Binary_Search(A, p, q, v);
		}
		if(v > A[q]){
			Binary_Search(A, q + 1, r, v);
		}
		if(v == A[q]){
			printf("%d", q);
		}
	}
	else{
		printf("v is not exist");
	}
}

int main(){
	int n, v;
	printf("input n:\n");
	while(scanf("%d", &n) != EOF){
		int A[n];
		printf("input A:\n");
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		printf("input v:\n");
		scanf("%d", &v);
		std::sort(A, A + n);
		Binary_Search(A, 0, n - 1, v);
	}
	return 0; 
}
