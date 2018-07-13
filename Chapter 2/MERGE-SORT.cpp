#include <stdio.h>
#define INF 0x3f3f3f3f

void MERGE(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	//caution
	int L[n1 + 2], R[n2 + 2];
	for(int i = 1; i < n1 + 1; i++){
		L[i] = A[p + i - 1];
	} 
	for(int j = 1; j < n2 + 1; j++){
		R[j] = A[q + j];
	}
		
	//set guard
	L[n1 + 1] = INF;
	R[n2 + 1] = INF;
	int i, j;
	i = 1;
	j = 1;
	for(int k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i += 1;
		}
		else{
			A[k] = R[j];
			j += 1;
		}
	}
} 

void MERGE_SORT(int A[], int p, int r){
	if(p < r){
		int q;
		q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int A[n];
		printf("input A:\n");
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		MERGE_SORT(A, 0, n - 1);
		for(int i = 0; i < n; i++){
			printf("%d", A[i]);
			printf(" ");
		}
	}
	return 0; 
}
