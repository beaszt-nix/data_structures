#include <stdio.h>
#include <stdlib.h>
typedef struct vector {
    int *buf;
    int length;
    int cur_length;
} vector;
vector *vector_init(int n){
	vector *a = (vector *)malloc(sizeof(vector));
    a->buf = (int *)malloc(sizeof(int) * n);
    a->length = n;
    a->cur_length = -1;
    return a;
}
void resize(vector *a, int n){
    int *temp = realloc(a->buf, n);
    a->buf = temp;
    printf("%d\n", a->length);
    if (n < a->cur_length)
        a->cur_length = n-1;
    a->length = n;
}
int isFull(vector *a){
    if (a->cur_length == (a->length - 1))
        return 1;
    return 0;
}
int size(vector *a){
    return a->cur_length + 1;
}
int resize_check(vector *a){
    if (size(a)  > (int) (0.75*a->length) )
        return 1;
    return 0;
}
void push_back(vector *a, int val){
    if (isFull(a) == 1){
        printf("Error, vector full\n");
        return;
    }
    a->buf[++(a->cur_length)] = val;
    if (resize_check(a) == 1)
        resize(a, 2*a->length);
}
void insert_n(vector *a, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &(a->buf[i]));
    }
}
int get(vector *a, int i){
    if (i <= a->cur_length)
        return a->buf[i];
}
void put(vector *a, int i, int val){
    if (i <= a->cur_length)
        a->buf[i] = val;
}
void display(vector *a){
    int i = 0;
    for (;i <= a->cur_length; i++)
        printf("%d ", a->buf[i]);
    printf("\n");
}
int main(){
    vector *a = vector_init(10);
    int n;
    printf("%d\n", a->length);
    scanf("%d", &n);
    while (n--){
        int temp;
        scanf("%d", &temp);
        push_back(a, temp);
    }
    display(a);
    printf("%d\n", a->length);
}
