#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <iostream>
using namespace std;

#define FNV_PRIME 16777619
#define FNV_OFFSET 0x811c9dc5

typedef struct node {
    int data;
    struct node *left, *right, *parent;
} node;

uint32_t fnv_generic(void *a, size_t len){
    uint32_t hash = FNV_OFFSET;
    uint8_t *b = (uint8_t *)malloc(len);
    memcpy(b, a, len);
    for (int i = 0; i < len; i++){
        hash = hash ^ b[i];
        hash = hash * FNV_PRIME;
    }
    return hash;
}

template<class T>
class nodeT{
private:
    T val;
public:
    nodeT *next, *nnode;
    nodeT(T val){
        this->val = val;
        next = NULL;
        nnode = NULL;
    }
};

int main(){
    int n = 1e9+7;
    char arr[1000] = "asdfghjk";
    unsigned long long a = 12345678765432;
    node c;
    c.data = 111111;
    c.left = NULL;
    c.right = NULL;
    c.parent = NULL;
    nodeT<int> *d = new nodeT<int>(3456);
    printf("int %u\n", fnv_type_generic(&n, sizeof(n)));
    printf("ull %u\n", fnv_type_generic(&a, sizeof(a)));
    printf("string %u\n", fnv_type_generic(arr, strlen(arr)));
    printf("node(struct) %u\n", fnv_type_generic(&c, sizeof(c)));
    printf("node(class) %u\n", fnv_type_generic(d, sizeof(d)));
}
