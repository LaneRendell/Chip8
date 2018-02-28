#include "globals.h"

#define mix(a,b,c) \
{ \
  a -= b; a -= c; a ^= (c>>13); \
  b -= c; b -= a; b ^= (a<<8); \
  c -= a; c -= b; c ^= (b>>13); \
  a -= b; a -= c; a ^= (c>>12);  \
  b -= c; b -= a; b ^= (a<<16); \
  c -= a; c -= b; c ^= (b>>5); \
  a -= b; a -= c; a ^= (c>>3);  \
  b -= c; b -= a; b ^= (a<<10); \
  c -= a; c -= b; c ^= (b>>15); \
}


uint32 hash(uint32 *Key, uint32 keyLength, uint32 seed)
{
    uint32 length;
    register uint32 len, a, b, c;
    // Setup internal state
    length = keyLength;
    len = length;

    a = b = 0x9e3779b9;   // Golden ratio, truncated arbitrary value
    c = seed;

    // Handle the majority of the keys.
    while (len >= 12)
    {
        a += (Key[0] + ((uint16)Key[1] << 8) + ((uint16)Key[2] << 16)
              + ((uint16)Key[3] << 24));
        b += (Key[4] + ((uint16)Key[5] << 8) + ((uint16)Key[6] << 16)
              + ((uint16)Key[7] << 24));
        c += (Key[8] + ((uint16)Key[9] << 8) + ((uint16)Key[10] << 16)
              + ((uint16)Key[11] << 24));
        mix(a, b, c);
        // Advance through keys and decrease count.
        Key += 12;
        len -= 12;
    }

    // Handle the last eleven bytes
    c += length;
    switch (len)
    {
        case 11: c += ((uint16) Key[10] << 24);
        case 10: c += ((uint16) Key[9] << 16);
        case 9: c += ((uint16) Key[8] << 8);
        // First byte of c is reserved for length
        case 8: b += ((uint16) Key[7] << 24);
        case 7: b += ((uint16) Key[6] << 16);
        case 6: b += ((uint16) Key[5] << 8);
        case 5: b += ((uint16) Key[4]);
        case 4: a += ((uint16) Key[3] << 24);
        case 3: a += ((uint16) Key[2] << 16);
        case 2: a += ((uint16) Key[1] << 8);
        case 1: a += ((uint16) Key[0]);
    }

    mix(a, b, c);

    return c;
}
