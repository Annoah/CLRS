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
			//第一步定位以及定位在已排序队列末尾时出现问题，该if结构解决该问题 
			if((k == 0 && a[k] < key) || (l == k && a[k] < key)){
				continue;
			}
			//虽然定位是O(lgn)
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
