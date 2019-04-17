#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstdlib>
using namespace std;

#define FNV_PRIME32 16777619
#define FNV_OFFSET32 0x811c9dc5

template<class X, class Y>
class hash_table{
typedef struct node {
	X key;
	Y val;
} node;
private:
	node **buf;
	size_t len;
	uint32_t hash(const void *key, size_t len){
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
	int quadratic_probe(int i){
		int j = 1;
		if (buf[i] == NULL)
			return i;
		while ( (i + j*j)%len != i && (i - j*j)%len != i){
			if (buf[(i + j*j)%len] == NULL)
				return (i+j*j)%len;
			else if (buf[(i - j*j)%len] == NULL)
				return (i-j*j)%len;
			j++;
		}
		return -1;
	}
public:
	hash_table(size_t n){
		this->len = n;
		buf = (node **)malloc(n * sizeof(node *));
	}
	int search(int i, X key){
		if (buf[i] == NULL)
			return -1;
		if (buf[i]->key == key)
			return i;
		int j = 1;
		while ((i + j*j)%len != i && (i - j*j)%len != i){
			if (buf[(i + j*j)%len] == NULL){
				return -1;
			}
			else if (buf[(i + j*j)%len] != NULL){
				if (buf[(i + j*j)%len]->key ==  key)
					return (i+ j*j)%len;	
			}
			else if (buf[(i - j*j)%len] == NULL){
					return -1;
			}
			else if (buf[(i - j*j)%len] != NULL){
				if (buf[(i - j*j)%len]->key ==  key)
					return (i- j*j)%len;	
			}
			j++;
		}
		return -1;
	}
	Y& operator[](X key){
		int i = hash(&key,sizeof(X))%len;
		int j = search(i, key);
		if (j != -1){
			return buf[i]->val;
		}
		else {
			cout << "key value pair doesn't exist" << endl;
		}
	}
	void insert(X key, Y val){
		int i = hash(&key,sizeof(X))%len;
		i = quadratic_probe(i);
		if (i == -1){
			cout << "FULL" << endl;
			return;
		}
		buf[i] = (node *)malloc(sizeof(node));
		buf[i]->key = key;
		buf[i]->val = val;
	}
	void del_pair(X key){
		int i = hash(&key,sizeof(X))%len;
		i = search(i,key);
		if (i != -1){
			free(buf[i]);
			buf[i] = NULL;
			return;
		}
		cout << "Void delete" << endl;
	}
};

int main(){
	hash_table<string, int> a(1000);
	vector<string> temp;
	for(int i = 0; i < 10; i++){
		string tmp;
		cin >> tmp;
		temp.push_back(tmp);
		a.insert(tmp,i);
	}
	for (int i = 0; i < temp.size(); i++){
		cout << a[temp[i]] << endl;
	}
}
