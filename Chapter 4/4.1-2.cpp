#include <stdio.h>
#define INF 0x3f3f3f3f

struct FMSV{
	int low;
	int high;
	int sum;
};

struct FMSV Find_Maximum_Subarray_Violent(int A[], int low, int high){
	FMSV R;
	R.sum = -INF;
	for(int i = low; i <= high; i++){
		int sum = 0;
		for(int j = i; j <=high; j++){
			sum += A[j];
			if(sum > R.sum){
				R.sum = sum;
				R.low = i;
				R.high = j;	
			}
		}
	}
	return R;
}

int main(){
	FMSV R;
	/*
	int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	R = Find_Maximum_Subarray_Violent(A, 0, 15);
	printf("%d %d %d", R.low, R.high, R.sum);
	*/ 
	int n;
	while(scanf("%d", &n) != EOF){
		int A[n];
		int low, high, sum;
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		R = Find_Maximum_Subarray_Violent(A, 0, n - 1);
		printf("%d %d %d", R.low, R.high, R.sum);
	}
}
