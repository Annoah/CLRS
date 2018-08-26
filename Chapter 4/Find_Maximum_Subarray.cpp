#include <stdio.h>
#define INF 0x3f3f3f3f

struct FMS{
	int low;
	int high;
	int sum;
};

struct FMS Find_Max_Crossing_Subarray(int A[], int low, int mid, int high){
	FMS R;
	int left_sum = -INF;
	int sum = 0;
	for(int i = mid; i >= low; i--){
		sum += A[i];
		if(sum > left_sum){
			left_sum = sum;
			R.low = i;
		}
	}
	int right_sum = -INF;
	sum = 0;
	for(int j = mid + 1; j <= high; j++){
		sum += A[j];
		if(sum > right_sum){
			right_sum = sum;
			R.high = j;
		}
	}
	R.sum = left_sum + right_sum;
	return R;
}

struct FMS Find_Maximum_Subarray(int A[], int low, int high){
	FMS end, left, right, cross;
	if(high == low){
		end.low = low;
		end.high = high;
		end.sum = A[low];
		return end;
	}
	else{
		int mid = (low + high) / 2;
		left = Find_Maximum_Subarray(A, low, mid);
		right = Find_Maximum_Subarray(A, mid + 1, high);
		cross = Find_Max_Crossing_Subarray(A, low, mid, high);
		if((left.sum >= right.sum) and (left.sum >= cross.sum)){
			return left;
		}
		if((right.sum >= left.sum) and (right.sum >= cross.sum)){
			return right;
		}
		if((cross.sum >= right.sum) and (cross.sum >= left.sum)){
			return cross;
		}
	}
}

int main(){
	FMS R;
	/* 
	int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	R = Find_Maximum_Subarray(A, 0, 15);
	printf("%d %d %d", R.low, R.high, R.sum);
	*/ 
	int n;
	while(scanf("%d", &n) != EOF){
		int A[n];
		int low, high, sum;
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		R = Find_Maximum_Subarray(A, 0, n - 1);
		printf("%d %d %d", R.low, R.high, R.sum);
	}
}
