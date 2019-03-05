#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void qSort(int *arr, int l, int h){
	if (l < h){
		int i = l+1, j = h;
		int pivot = arr[l];
		while(i < j){
			while(arr[i] <= pivot && i < j)
				i++;
			while(arr[j] > pivot && i < j)
				j--;
			if (i < j){
				swap(arr+i, arr+j);
				j--;
				i++;
			}
		}
		qSort(arr, l, j);
		qSort(arr, j+1, h);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	qSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}