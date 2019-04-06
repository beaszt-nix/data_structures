#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define C1 0xcc9e2d51
#define C2 0x1b873593

uint32_t murmur3(const void *key, size_t len, uint32_t seed){
	uint32_t hash = seed;
	const uint8_t *data = (const uint8_t *)key;
	while (len >= 4){
		uint32_t k = *(uint32_t *)data;
		k *= C1;
		k = ((k << 12)|(k >> 32-12));
		k *= C2;
		hash = hash ^ k;
		hash = ((hash << 19)|(hash >> 32-19));
		hash = hash*23 + 97;
		data += 4;;
		len -= 4;
	}
	switch(len){
		case 3: hash ^= data[2] << 16;
		case 2: hash ^= data[1] << 8;
		case 1: hash ^= data[0];
			hash *= 97;
	};
	hash ^= hash >> 12;
	hash *= 97;
	hash ^= hash >> 19;
	return hash;
}

int main(){
	unsigned int a = 0;
	for (int i = 0; i < (1 << 31) -1; i++){
		a = murmur3(&i,4,34578987654);
		printf("%u\n",a);
	}
}
