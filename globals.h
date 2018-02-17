#if !defined(GLOBALS_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2015 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

#define GLOBALS_H

#include <SDL.h>

//*******************************************************Defines************/

#define MEM_SIZE 0x1000
#define SP_START 0x252   // Where does the Stack pointer start?
#define ROM_LOAD 0x200


#define CPU_CLEAR_SCREEN 0xE0
#define CPU_RET 0xEE

typedef unsigned char byte;  // Byte of memory
// A word is two bytes. Access it as a whole or individually
typedef union
{
    unsigned short WORD;
    struct {
        #ifdef WORDS_LITTLE_ENDIAN

        byte high, low;

        #else

        byte low, high;

        #endif
    } BYTE;
} word;

typedef struct
{
    byte v[0x10];  // Registers
    word i;        // Index Register
    word pc;       // Program Counter
    word sp;       // Stack pointer
    byte dt;       // Delay Timer
    byte st;       // sound timer
    word operand;  // The current operand
} registerSet;

typedef struct
{
    registerSet regs;
    byte memory[4096];
    byte gfx[64*32];
    byte key[16];
    word stack[16];
} chip;


static chip mainChip = {0};
static registerSet chipReg = {0};
static byte *chipMem;

#endif
