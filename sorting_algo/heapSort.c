#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int *arr, int l, int r){
	int i, j = r;
	while (j > l){
		i = j;
		while (i > l){
			if (arr[i] > arr[i/2]){
				swap(arr+i, arr+(i/2));
				i /= 2;
			}
			else
				break;	
		}
		if (arr[i] > arr[i+1] && i > l)
			swap(arr + i, arr + i + 1);
		j--;
	}
}
void heap_sort(int *arr, int l, int r){
	if (l < r){
		heapify(arr,l,r);
		swap(arr+l,arr+r);
		heap_sort(arr, l, r-1);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", arr+i);
	}
	heap_sort(arr,0,n-1);
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
