#include <stdio.h>
#include <algorithm>

int Binary_Search(int A[], int p, int r, int v){
	if(p < r){
		int q;
		q = (p + r) / 2;
		if(v < A[q]){
			//注意：递归中的return 
			return Binary_Search(A, p, q, v);
		}
		if(v > A[q]){
			return Binary_Search(A, q + 1, r, v);
		}
		if(v == A[q]){
			return q; 
		}
	}else{
		return p;
	}
	//虽然定位是O(lgn)
}

int main(){
	int n;
	printf("input n:\n");
	while(scanf("%d",&n) != EOF){
		int a[n];
		printf("input A[%d]:\n", n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for(int j = 1; j < n; j++){
			int key = a[j]; 
			int k = j - 1;
			int l = Binary_Search(a, 0, k, key);
			printf("locate:%d ",l);
			//但是定位之后还是要移动该位置之后的所有元素，因此还是O(lgn^2) = O(n)
			while(k >= l){
				a[k + 1] = a[k];
				k = k - 1;
			}
			a[l] = key;
		} 
		printf("output A[%d]:\n", n);
		for(int i = 0; i < n; i++){
			printf("%d", a[i]);
			printf(" ");
		}
	}
} 
