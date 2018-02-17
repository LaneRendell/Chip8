#if !defined(GLOBALS_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2015 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

#define GLOBALS_H

#include "./dependencies/SDL.h"
//#include <SDL.h> Uncomment if you've got it on your system and want your version I guess

//*******************************************************Defines************/

#define MEM_SIZE 0x1000
#define SP_START 0x252   // Where does the Stack pointer start?
#define ROM_LOAD 0x200
#define FONTSET_LENGTH 80

#define OPCODE_LENGTH 2

#define CPU_CLEAR_SCREEN 0xE0
#define CPU_RET 0xEE


//*********************************** Structs *****************************/

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


// ********************************* Global declarations *************/
static chip mainChip = {0};
static registerSet chipReg = {0};
static byte *chipMem;
static byte fontset[80] =
{
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

#endif
