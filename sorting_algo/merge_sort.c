#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int h, int mid){
	int left[(h-l)/2 +1], right[(h-l)/2 +1];
	int i = 0, j = 0;
	for(int k = l; k <= mid; k++)
		left[i++] = arr[k];
	for (int k = mid+1; k <= h; k++)
		right[j++] = arr[k];
	int li = 0, ri = 0, k = l;
	while (li != i && ri != j){
		if (left[li] <= right[ri])
			arr[k++] = left[li++];
		else
			arr[k++] = right[ri++];
	}
	while (li != i)
		arr[k++] = left[li++];
	while (ri != j)
		arr[k++] = right[ri++];
}
void mergeSort(int arr[], int l, int h){
	if (l < h){
		int mid = (h + l)/2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, h);
		merge(arr, l, h, mid);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d",(arr+i));
	mergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
