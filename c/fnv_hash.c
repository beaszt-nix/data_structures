#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#define BYTESIZE 256
#define FNV_PRIME 16777619
#define FNV_OFFSET 0x811c9dc5

uint32_t fnv_int(uint32_t n){
    uint32_t hash = FNV_OFFSET;
    for (int i = 0; i < 4; i++){
        hash = hash ^ ((n%(int)pow(BYTESIZE,i+1))/(int)pow(BYTESIZE,i));
        hash = hash * FNV_PRIME;
    }
    return hash;
}

uint32_t fnv_long(uint64_t n){
	uint32_t hash = FNV_OFFSET;
	for (int i = 0; i < 8; i++){
		hash = hash ^ ((n%(int)pow(BYTESIZE,i+1))/(int)pow(BYTESIZE,i));
		hash *= FNV_PRIME;
	}
	return hash;
}

uint32_t fnv_string(char *a){
	uint32_t hash = FNV_OFFSET;
	for (int i = 0; i < strlen(a); i++){
		hash = hash ^ a[i];
		hash *= FNV_PRIME;
	}
	return hash;
}
//for structures and classes use fnv generic cpp