#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FNV_PRIME32 16777619
#define FNV_OFFSET32 0x811c9dc5

uint32_t fnv_hash(const void *key, size_t len){
	uint32_t hash = FNV_OFFSET32;
	const uint8_t *data = (const uint8_t *)key;
	while (len > 0){
		hash = hash ^ *data;
		hash = hash * FNV_PRIME32;
		data += 1;
		len--;
	}
	return hash;
}
