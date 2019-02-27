#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void radix_sort(int *arr, int l, int h){
    int err=0;
    for (int i = 0; i < sizeof(int) + 1; i++){
        printf("\n%d. ", i+1);
        int pos[256] = { 0 };
        int st[256][h-l];
        for (int j = l; j < h; j++){
            int temp = (arr[j]%(int)pow(256, i+1))/(int)pow(256, i);
            st[temp][pos[temp]++] = arr[j];
        }
        int t = l;
        for (int i = 0; i < 256; i++){
            for (int j = 0; j < pos[i]; j++){
                arr[t] = st[i][j];
                printf("%d ", arr[t]);
                t++;
            }
        }
        if (pos[0] == (h-l))
            break;
    }
}
int main(){
    int n;
    scanf("%d",  &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    radix_sort(arr, 0, n);
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}