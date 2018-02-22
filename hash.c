#include "hash.h"
#include <malloc.h>
#include <stdio.h>


void HashValue(HashEntry *HashEntry)
{
    int key = 0;

    key = HashEntry->key;

    if (HashEntry->key == 0)
    {
        // Flip the bits
        int keyShift = ((1 << 0) | (1 << 1) | (1 << 3));
        key = key ^ ((1 << 0) | (1 << 1) | (1 << 3));

        // Update the key in the struct
        HashEntry->key = key;
    }
    
}

HashEntry* NewHashEntry(int key, int data)
{
    HashEntry *Entry = malloc(sizeof(HashEntry));
    Entry->key = key;
    Entry->data = data;

    return Entry;

}


HashTable* NewHashTable()
{
    HashTable *hash_table = malloc(sizeof(HashTable));

    hash_table->size = HASH_TABLE_SIZE;
    hash_table->count = 0;
    hash_table->entries = calloc((size_t)hash_table->size, sizeof(HashEntry *));

    return hash_table;
}

void DeleteHashEntry(HashEntry *Entry)
{
    free(Entry);
}

void DeleteHashTable(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        HashEntry *Entry = table->entries[i];
        if (Entry != NULL)
        {
            DeleteHashEntry(Entry);
        }

        free(table->entries);
        free(table);
    }
}

void InsertEntry(HashTable *table, int *key, int *data)
{
    HashEntry *Entry = NewHashEntry(*key, *data);

    int index = 0;
}
