#if !defined(HASHING_H)
#define HASHING_H

// This code has been modified from CMPH.
// TODO: Link GPL?

// Generic data type for our hash table

typedef struct
{
    void *data;
    uint8 numKeys;
} HashTableGeneric;

// If we want to hash an array of structs
HashTableGeneric *hashtbl_struct(void *strucArray,
                                 uint16 struct_size,
                                 uint8 numKeys);

// A normal array of keys to be hashed.
HashTableGeneric *hashtbl_array(void **entriesArray,
                                uint16 numKeys);

uint32 Keys[] =
{
    0xF07, 0xF0A, 0xF15, 0xF18,
    0xF1E, 0xF29, 0xF33, 0xF55,
    0xF65
};

inline uint32 hash(uint32 *Key, uint32 keyLength, uint32 seed);


#endif
