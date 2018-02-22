#if !defined(HASH_H)
#define HASH_H

#define HASH_TABLE_SIZE 9

// TODO: I dunno do we want this to be more generic?
// We should only need int keys and data.
typedef struct HashEntry_
{
    int key;
    int data;
} HashEntry;

typedef struct HashTable_
{
    int size;
    int count;
    HashEntry **entries;
} HashTable;

HashEntry* NewHashEntry(int key, int data);
HashTable* NewHashTable();
void HashValue(HashEntry *HashEntry);
void DeleteHashEntry(HashEntry *Entry);
void DeleteHashTable(HashTable *Table);
void InsertEntry(HashTable *table, int *key, int *data);
void SearchTable(HashTable *table, int *key);

#endif
