#include "hash.h"
#include <malloc.h>
#include <stdio.h>

#define HASH_TABLE_SIZE 9

void HashValue(HashEntry *HashEntry)
{
    int key = 0;

    key = 0xF029;

    printf("%04X\n", HashEntry->key);

    if (HashEntry->key == 0)
    {
        // Flip the bits
        int keyShift = ((1 << 0) | (1 << 1) | (1 << 3));
        printf("Key Shift: %04X\n", keyShift);
        key = key ^ ((1 << 0) | (1 << 1) | (1 << 3));

        printf("%04X\n", key);

        // Update the key in the struct
        HashEntry->key = key;
    }
    
}
