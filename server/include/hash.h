/*
	Hash functions for Client/Agent Management.
*/

#include <search.h>

#define ENTRY	hash_element;

inline int create_hash(int max_element);

inline int add_to_hash(hash_element *data);

inline hash_element* hash_search(hash_element *key,FIND);

inline int destroy_hash();


