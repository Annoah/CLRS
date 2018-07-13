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
		a[p] = key;
	}
}

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
//			while(i >= 0 && a[i] > key){
//				a[i + 1] = a[i];
//				i = i - 1;
//			}
			Binary_Search(a, 0, i, a[j]);
			a[i + 1] = key;
		} 
		for(int i = 0; i < n; i++){
			printf("%d", a[i]);
		}
	}
} 
