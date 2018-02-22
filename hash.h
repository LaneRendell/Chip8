#if !defined(HASH_H)
#define HASH_H

typedef struct HashEntry_
{
    int key;
    int data;
} HashEntry;

void HashValue(HashEntry *HashEntry);

#endif
