#if !defined(HASH_H)
#define HASH_H

typedef struct HashEntry_
{
    void *key;
    void *data;
} HashEntry;

void *Hash(void *Data)
{
    void *HashVal = *(int *)Data % 9;
}

#endif
